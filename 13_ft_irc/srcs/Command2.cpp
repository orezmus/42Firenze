#include "Server.hpp"

void Server::inviteChannel(int client_fd, const std::string &msg)
{
	std::istringstream iss(msg);
	std::string mesg, nick, channel_name;
	iss >> mesg >> nick >> channel_name;
	channel_name.erase(channel_name.find_last_not_of(" \n\r\t") + 1);
	nick.erase(nick.find_last_not_of(" \n\r\t") + 1);

	if (channel_name[0] != '#' || channel_name.empty() || nick.empty())
	{
		sendToClient(client_fd, "Invalid command. Usage: /INVITE <nickname> #<channel>\n");
		return ;
	}
	std::string name = channel_name.substr(1);
	
	if (checkChannel(client_fd, name))
		return ;

	int target_fd = getClientFd(nick); 
	if (_channels[name].isMember(target_fd))
	{
		sendToClient(client_fd, "User is already in the channel\n");
		return ;
	}
	Client* target_client = getClient(target_fd);

	if (target_client == NULL) 
	{
		sendToClient(client_fd, "No such user\n");
		return;
	}

	_channels[name].addClient(target_fd);
	sendToClient(client_fd, "You invited " + nick + " to the channel " + channel_name + "\n");
	sendToClient(target_fd, "You have been invited to the channel " + channel_name + "\n");
	
	std::string joinMessage = ":" + nick + " JOIN :" + channel_name + "\r\n";
	sendToClient(target_fd, joinMessage);

	sendChannelListToClient(client_fd, name);
	sendChannelListToClient(target_fd, name);
}

void Server::kickChannel(int client_fd, const std::string &msg)
{
	std::istringstream iss(msg);
	std::string cmd, network, channel, nick, reason;
	iss >> cmd >> network >> channel;

	if (network[0] == '#' && channel[0] != '#')
	{
		nick = channel;
		channel = network;
	}
	else
		iss >> nick;
	
	std::getline(iss >> std::ws, reason);

	channel.erase(channel.find_last_not_of(" \n\r\t") + 1);
	nick.erase(nick.find_last_not_of(" \n\r\t") + 1);
	
	if (channel[0] != '#' || channel.empty() || nick.empty())
	{
		sendToClient(client_fd, "Invalid command. Usage: /KICK #<channel> <nickname> <reason>\n");
		return ;
	}

	if (nick[0] == ':')
		nick = nick.substr(1);

	channel = channel.substr(1);
	
	if (checkChannel(client_fd, channel))
		return ;

	if (_channels[channel].isMember(getClientFd(nick)))
	{
		if (reason.empty())
			reason = " no reason";
		std::cout << "Operator kicked " << nick << std::endl;
		partChannel(getClientFd(nick), "PART #" + channel);
		sendToClient(getClientFd(nick), "You have been kicked from the channel by an operator. Reason :" + reason + "\n");
		
		broadcast(channel, _client[client_fd].getNickname() + "!" + _client[client_fd].getNickname() + "@irc KICK #" + channel + " " + nick + reason + "\n");
	}
	else
		sendToClient(client_fd, "No such user in the channel\n");
	//sendChannelListToClient(client_fd, channel);
}

void Server::topicChannel(int client_fd, const std::string &msg)
{
	std::istringstream iss(msg);
	std::string message, channel, topic;
	iss >> message >> channel;
	std::getline(iss >> std::ws, topic);
	channel.erase(channel.find_last_not_of(" \n\r\t") + 1);
	if (channel[0] != '#' || channel.empty())
	{
		sendToClient(client_fd, "Invalid command. Usage: /TOPIC #<channel> :<topic>\n");
		return ;
	}
	channel = channel.substr(1);
	if (_channels.find(channel) == _channels.end())
	{
		sendToClient(client_fd, "No such channel\n");
		return ;
	}
	if (!_channels[channel].isMember(client_fd))
	{
		sendToClient(client_fd, "You are not in the channel\n");
		return;
	}
	if (_channels[channel].isRestrictedTopic() && !_channels[channel].isOperator(client_fd))
	{
		sendToClient(client_fd, "Topic is restricted in this channel\n");
		return ;
	}
    if (topic.empty())
	{
        // Se il topic è vuoto, invia il messaggio appropriato per informare che non c'è topic
        if (_channels[channel].getTopic().empty())
            sendToClient(client_fd, ":" + _client[client_fd].getServername() + " 331 " + _client[client_fd].getNickname() + " #" + channel + " :No topic is set\n");
        else
            sendToClient(client_fd, ":" + _client[client_fd].getServername() + " 332 " + _client[client_fd].getNickname() + " #" + channel + " :" + _channels[channel].getTopic() + "\n");
    }
	else
	{
        // Imposta il nuovo topic e invia il messaggio `TOPIC` al canale
        topic = topic.substr(1); // Rimuovi il primo carattere ":"
        _channels[channel].setTopic(topic);
        sendToClient(client_fd, "You have set a Topic in the channel #" + channel + "\n");
        broadcast(channel, ":" + _client[client_fd].getNickname() + "!" + _client[client_fd].getUsername() + "@" + _client[client_fd].getHostname() + " TOPIC #" + channel + " :" + _channels[channel].getTopic() + "\n");
	}
}

void Server::modeChannel(int client_fd, const std::string &msg)
{
	std::istringstream iss(msg);
	std::string message, channel, flag;
	iss >> message >> channel >> flag;

	channel.erase(channel.find_last_not_of(" \n\r\t") + 1);
	flag.erase(flag.find_last_not_of(" \n\r\t") + 1);

	Client& Client = _client[client_fd];
	if (channel[0] != '#' || channel.empty())
	{
		sendToClient(client_fd, "Invalid command. Usage: /MODE #<channel> <flag> <option>\n");
		return ;
	}
	channel = channel.substr(1);
	if (flag.empty())
	{
		Channel& Channel = _channels[channel];
    	std::string mode = "+"; // 기본적으로 '+'로 시작
    
		// 채널 모드 확인 예시
		if (Channel.getMode('i'))
			mode += "i"; // 초대 전용 채널인지 확인
		if (Channel.getMode('t'))
			mode += "t"; // 토픽 변경 권한 제한 여부
		if (Channel.getMode('k'))
			mode += "k"; // 비밀번호 설정 여부
		if (Channel.getMode('l'))
			mode += "l"; // 최대 인원 제한 여부

		// 클라이언트에게 현재 모드 전달
		sendToClient(client_fd, ":server_name 324 " + Client.getNickname() + " " + channel + " " + mode + "\n");
		return;
	}
	if (checkChannel(client_fd, channel))
		return ;
	if (flag == "+i")
	{
		sendToClient(client_fd, "Channel mode is set invite only\n");
		std::cout << "Operator has set invete only mode" << std::endl;
		_channels[channel].setMode('i', true);
	}
	else if (flag == "-i")
	{
		sendToClient(client_fd, "Channel mode is unset invite only\n");
		std::cout << "Operator has unset invete only mode" << std::endl;
		_channels[channel].setMode('i', false);
	}
	else if (flag == "+t")
	{
		sendToClient(client_fd, "Channel mode is set topic restricted\n");
		std::cout << "Operator has set topic restricted mode" << std::endl;
		_channels[channel].setMode('t', true);
	}
	else if (flag == "-t")
	{
		sendToClient(client_fd, "Channel mode is unset topic restricted\n");
		std::cout << "Operator has unset topic restricted mode" << std::endl;
		_channels[channel].setMode('t', false);
	}
	else if (flag == "+k")
	{
		std::string key;
		iss >> key;
		key.erase(key.find_last_not_of(" \n\r\t") + 1);
		if (key.empty())
		{
			sendToClient(client_fd, "Invalid command. Usage: /MODE #<channel> +k <key>\n");
			return ;
		}
		sendToClient(client_fd, "Channel is locked\n");
		std::cout << "Operator has locked channel" << std::endl;
		_channels[channel].setKey(key);
	}
	else if (flag == "-k")
	{
		sendToClient(client_fd, "Channel is unlocked\n");
		std::cout << "Operator has unlocked channel" << std::endl;
		_channels[channel].setKey("");
	}
	else if (flag == "+o")
	{
		std::string nick;
		iss >> nick;
		nick.erase(nick.find_last_not_of(" \n\r\t") + 1);
		if (nick.empty())
		{
			sendToClient(client_fd, "Invalid command. Usage: /MODE #<channel> o <nickname>\n");
			return ;
		}
		broadcast(channel, nick + " is given channel operator privilage\n");
		std::cout << "Operator has given operator privilage to " << nick << std::endl;
		_channels[channel].addOperator(getClientFd(nick));
		sendChannelListToClient(client_fd, channel);
		sendChannelListToClient(getClientFd(nick), channel);
	}
	else if (flag == "-o")
	{
		std::string nick;
		iss >> nick;
		if (nick.empty())
		{
			sendToClient(client_fd, "Invalid command. Usage: /MODE #<channel> o <nickname>\n");
			return ;
		}
		broadcast(channel, nick + " is taken channel operator privilage\n");
		std::cout << "Operator has taken operator privilage from " << nick << std::endl;
		_channels[channel].removeOperator(getClientFd(nick));
		sendChannelListToClient(client_fd, channel);
		sendChannelListToClient(getClientFd(nick), channel);
	}
	else if (flag == "+l")
	{
		int limit;
		iss >> limit;
		_channels[channel].setLimit(limit);
	}
	else if (flag == "-l")
		_channels[channel].setLimit(-1);
	else
	{
		sendToClient(client_fd, "Invalid mode\n");
		return ;
	}
}
