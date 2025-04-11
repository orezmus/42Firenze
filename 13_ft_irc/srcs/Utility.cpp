#include "Server.hpp"

void Server::sendToClient(int client_fd, const std::string &msg)
{
	send(client_fd, msg.c_str(), msg.length(), 0);
}

void Server::broadcast(const std::string &channel_name, const std::string &msg)
{
	if (_channels.find(channel_name) == _channels.end()) 
    {
		std::cout << "Channel " << channel_name << " does not exist\n";
		return;
	}

	Channel& channel = _channels[channel_name];
	std::vector<int>::const_iterator it;
	const std::vector<int> &members = channel.getMembers();
	for (it = members.begin(); it != members.end(); ++it) 
	{
		int client_fd = *it;
		sendToClient(client_fd, msg);
    }
}

std::vector<std::string> Server::findChannel(int client_fd)
{
	std::vector<std::string> channels;
    std::map<std::string, Channel>::iterator it;
    for (it = _channels.begin(); it != _channels.end(); ++it) 
	{
        if (it->second.isMember(client_fd))
            channels.push_back(it->first);
    }
	return channels;
}

int Server::getClientFd(const std::string &name)
{
    std::map<int, Client>::iterator it;
    for (it = _client.begin(); it != _client.end(); ++it)
    {
        if (it->second.getNickname() == name)
            return it->first;
    }
    return -1;
}

void Server::saveDefault(int client_fd, const std::string &msg)
{
	if (msg.compare(0, 5, "NICK ") == 0)
	{
		std::string nick = msg.substr(5);
		nick.erase(nick.find_last_not_of(" \n\r\t") + 1);
		_client[client_fd].setNickname(nick);
	}
	else if (msg.compare(0, 5, "USER ") == 0)
	{
		std::string name = msg.substr(5);
		name.erase(name.find_last_not_of(" \n\r\t") + 1);
		_client[client_fd].setUsername(name);
	}
}

int Server::checkChannel(int client_fd, const std::string &channel_name)
{
	if (_channels.find(channel_name) == _channels.end())
	{
		sendToClient(client_fd, "No such channel\n");
		return (1);
	}
	if (!_channels[channel_name].isMember(client_fd))
	{
		sendToClient(client_fd, "You are not in the channel\n");
		return (1);
	}
	if (!_channels[channel_name].isOperator(client_fd))
	{
		sendToClient(client_fd, "You are not an operator in this channel\n");
		return (1);
	}
	return (0);
}

Client* Server::getClient(int fd)
{
    std::map<int, Client>::iterator it = _client.find(fd);
    if (it != _client.end())
        return &(it->second);  // 클라이언트 포인터 반환
    return NULL;  // 클라이언트가 없을 때 nullptr 반환
}

void Server::sendChannelListToClient(int client_fd, const std::string &channel_name)
{
    // Controlla se il canale esiste
    if (_channels.find(channel_name) == _channels.end())
    {
        std::string errorMsg = "403 " + channel_name + " :No such channel\r\n";
        sendToClient(client_fd, errorMsg);
        return;
    }

    // Costruzione della lista degli utenti
    std::string userList;
    std::vector<int> clients = _channels[channel_name].getMembers();
	
    for (std::vector<int>::iterator it = clients.begin(); it != clients.end(); ++it)
    {
        if (_channels[channel_name].isOperator(*it))
        {
            if (*it != 0) // Aggiungi uno spazio tra i nickname
                userList += " @";
            userList += _client[*it].getNickname();
        }
        else
        {
            if (*it != 0) // Aggiungi uno spazio tra i nickname
                userList += " ";
            userList += _client[*it].getNickname();
        }
    }

    // Costruzione della risposta RPL_NAMREPLY
    std::string response = ":localhost 353 " + _client[client_fd].getNickname() + " = #" + channel_name + " :" + userList + "\r\n";
    
    // Log del messaggio inviato
    std::cerr << "Sending channel list: " << response << std::endl;

    // Invio della lista degli utenti al client
    sendToClient(client_fd, response);

    // Costruzione e invio del comando di fine lista RPL_ENDOFNAMES
    std::string endOfNames = ":localhost 366 " + _client[client_fd].getNickname() + " #" + channel_name + " :End of /NAMES list\r\n";
    sendToClient(client_fd, endOfNames);
}




std::string Server::getServerName() const
{
    char hostname[256];
    if (gethostname(hostname, sizeof(hostname)) == 0)
        return std::string(hostname);
    else
    {
        std::cerr << "Failed to get hostname\n";
        return "unknown";
    }
}
