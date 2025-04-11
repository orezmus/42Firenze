#include "Server.hpp"

void Server::joinChannel(int client_fd, const std::string &msg)
{
	std::istringstream iss(msg);
	std::string cmd, channel_name, password;
	iss >> cmd >> channel_name >> password;

	if (channel_name[0] == '#') 
	{
		std::string name = channel_name.substr(1);
		name.erase(name.find_last_not_of(" \n\r\t") + 1);

		Client& client = _client[client_fd];
		if (_channels.find(name) == _channels.end()) // Se il canale non esiste, crealo
		{
			_channels[name] = Channel(name);
			_channels[name].addClient(client_fd);

			// Aggiungi come operatore
			_channels[name].addOperator(client_fd);

			// Notifica la creazione del canale e l'unione
			std::cout << "Client " << client_fd << " created channel #" << name << std::endl;
			std::string joinMessage = ":" + client.getNickname() + " JOIN :" + channel_name + "\r\n";
			sendToClient(client_fd, joinMessage);			
		}	
		else // Se il canale esiste già
		{
			if (_channels[name].isInviteOnly()) // Controlla se il canale è solo su invito
			{
				sendToClient(client_fd, "This channel is invite only\r\n");
				return ;
			}
			if (_channels[name].isFull()) // Controlla se il canale è pieno
			{
				sendToClient(client_fd, "Channel is full\r\n");
				return ;
			}
			if (!_channels[name].isMember(client_fd)) // Se il client non è già membro
			{
				std::cout << password << std::endl;
				if (_channels[name].getKey().empty() || _channels[name].getKey() == password)
				{
					_channels[name].addClient(client_fd);
					std::string joinMessage = ":" + client.getNickname() + " JOIN :" + channel_name + "\r\n";
					_channels[name].broadcast(joinMessage); // Invia a tutti nel canale
				}
				else
				{
					sendToClient(client_fd, "Invalid password\r\n");
					return ;
				}
			}
			else
			{
				sendToClient(client_fd, "You are already in this channel #" + name + "\r\n");
				return;
			}
		}

		// Invia la lista degli utenti e il topic del canale
		sendChannelListToClient(client_fd, name);

		if (!_channels[name].getTopic().empty())
		{
			std::string topicMessage = ":YourServer 332 " + client.getNickname() + " #" + name + " :" + _channels[name].getTopic() + "\r\n";
			sendToClient(client_fd, topicMessage);
		}

		// Invia il messaggio di fine lista
		std::string endOfNames = ":YourServer 366 " + client.getNickname() + " #" + name + " :End of /NAMES list\r\n";
		sendToClient(client_fd, endOfNames);
	}
	else
	{
		sendToClient(client_fd, "Invalid channel name. Please use /join #<channel>\r\n");
	}
}


void Server::partChannel(int client_fd, const std::string &msg)
{
	std::istringstream iss(msg);
	std::string cmd,channel_name;
	iss >> cmd >> channel_name;
	channel_name.erase(channel_name.find_last_not_of(" \n\r\t") + 1);
	
	if (channel_name[0] == '#') 
	{
		std::string name = channel_name.substr(1);
		if (_channels.find(name) == _channels.end())
		{
			sendToClient(client_fd, "No such channel\n");
			return ;
		}
		if (_channels[name].isMember(client_fd))
		{
			_channels[name].removeClient(client_fd);
			std::vector<int> members = _channels[name].getMembers();
			for (std::vector<int>::iterator it = members.begin(); it != members.end(); ++it)
			{
					sendChannelListToClient(*it, name);
			}
			std::string partMessage = ":" + _client[client_fd].getNickname() + " PART :" + channel_name + "\r\n";
			sendToClient(client_fd, partMessage);
			broadcast(name, _client[client_fd].getNickname() + " has left the channel\n");
			return ;
		}
		else
			sendToClient(client_fd, "You are not in this channel\n");
	}
	else	
	{
		sendToClient(client_fd, "Invalid channel name. Please use /part #<channel>\n");
		return;
	}
}

void Server::whoChannel(int client_fd, const std::string &channel_name)
{
	std::string channel = channel_name.substr(1);
	if (_channels.find(channel) == _channels.end())
	{
		sendToClient(client_fd, "No such channel\n");
		return ;
	}
	std::vector<int> members = _channels[channel].getMembers();
	std::string status;
	for (size_t i = 0; i < members.size(); i++)
	{
		if (_channels[channel].isOperator(members[i]))
			status = "H@ :";
		else
			status = "H :";
		sendToClient(client_fd, "irc 352 :" + _client[client_fd].getNickname() + " " + channel_name + " " + _client[members[i]].getUsername() + " " + _client[members[i]].getHostname() + " " + _client[members[i]].getServername() +  " " + _client[members[i]].getNickname() + status + _client[members[i]].getRealname() + "\n");
		// 서버이름 352 채널이름 사용자이름 호스트이름 서버네임 닉네임 상태:실명
	}
	sendToClient(client_fd, "irc 315 :" + _client[client_fd].getNickname() + " " + channel_name + " :End of WHO list\n");
}

void Server::whoNick(int client_fd, const std::string &nickname)
{
	if (findChannel(getClientFd(nickname)).empty())
		sendToClient(client_fd, nickname + "is not in any channel\n");
	else
	{
		std::vector<std::string> channels = findChannel(getClientFd(nickname)); //nick클라이언트가 속한 채널 목록
		std::string status;
		for (size_t i = 0; i < channels.size(); i++)
		{
			if (_channels[channels[i]].isOperator(getClientFd(nickname)))
				status = "H@ :";
			else
				status = "H :";

			sendToClient(client_fd, "irc 352 :" + _client[client_fd].getNickname() + " #" + channels[i] + " " + _client[getClientFd(nickname)].getUsername() + " " + _client[getClientFd(nickname)].getHostname() + " " + _client[getClientFd(nickname)].getServername() + " " + _client[getClientFd(nickname)].getNickname() + status + _client[getClientFd(nickname)].getRealname() + "\n");
		}
		sendToClient(client_fd, "irc 315 :" + _client[client_fd].getNickname() + " " + nickname + " :End of WHO list\n");
	}
}
