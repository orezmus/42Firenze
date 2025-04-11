#include "Server.hpp"

Server::Server(const std::string &port, const std::string &password) : _port(port), _password(password), _server_socket(-1) {}

Server::~Server()
{
	for (size_t i = 0; i < _clients.size(); i++)
	{
		if (_clients[i].fd != -1)
			close(_clients[i].fd);
		if (_server_socket != -1)
			close(_server_socket);
	}
}

void Server::removeClient(int client_fd)
{
	_clients.erase(std::remove_if(_clients.begin(), _clients.end(), IsClientFd(client_fd)), _clients.end());
}

void Server::setupServer()
{
	_server_socket = socket(AF_INET, SOCK_STREAM, 0);
	if (_server_socket == -1)
	{
		std::cerr << "Failed to create server socket" << std::endl;
		exit(EXIT_FAILURE);
	}  
	std::cout << "Server socket created: " << _server_socket << std::endl;
	
	int opt = 1;
	if (setsockopt(_server_socket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)) == -1)
	{
		std::cerr << "Failed to set socket options" << std::endl;
		exit(EXIT_FAILURE);
	}

	fcntl(_server_socket, F_SETFL, O_NONBLOCK);

	struct sockaddr_in addr;
	addr.sin_family = AF_INET; 
	addr.sin_addr.s_addr = INADDR_ANY;
	addr.sin_port = htons(std::atoi(_port.c_str()));

	if (bind(_server_socket, (struct sockaddr *)&addr, sizeof(addr)) == -1)
	{
		std::cerr << "Failed to bind server socket" << std::endl;
		exit(EXIT_FAILURE);
	}
	std::cout << "Server socket bound to port " << _port << std::endl;
	
	if (listen(_server_socket, 10) == -1)
	{
		std::cerr << "Failed to listen on server socket" << std::endl;
		exit(EXIT_FAILURE);
	}
	std::cout << "Server socket is listening for connections" << std::endl;
	
	struct pollfd server_pfd = { _server_socket, POLLIN, 0 };
	_clients.push_back(server_pfd);
}

void Server::run()
{
	setupServer();
	std::cout << "Server started on port " << _port << std::endl;

	bool _running = true;
	while (_running)
	{
    	int poll_count = poll(_clients.data(), _clients.size(), -1);
    	if (poll_count == -1)
		{
        	std::cerr << "Polling error!" << std::endl;
        	break;
		}
		for (size_t i = 0; i < _clients.size(); i++)
		{
			if (_clients[i].revents & POLLIN)
			{
				if (_clients[i].fd == _server_socket)
					handleConnetions(); 
				else
					handleClient(_clients[i].fd);
			}
		}
	}
	closeServer(); // Funzione che chiude tutti i socket e rilascia le risorse
}

void Server::handleConnetions()
{
	struct sockaddr_in client_addr; 
	socklen_t client_addr_len = sizeof(client_addr);
	int clinet_socket = accept(_server_socket, (struct sockaddr *)&client_addr, &client_addr_len);

	if (clinet_socket == -1)
	{
		std::cerr << "Failed to accept client connection" << std::endl;
		return;
	}

	fcntl(clinet_socket, F_SETFL, O_NONBLOCK);

	struct pollfd client_pfd = { clinet_socket, POLLIN, 0 }; 
	_clients.push_back(client_pfd);

	_client[clinet_socket] = Client(clinet_socket);

	sendToClient(clinet_socket, "Welcome to the IRC server! Please authenticate with PASS <password>\n");
	std::cout << "New client connected: " << clinet_socket << std::endl;
}

void Server::handleClient(int client_fd)
{
	char buffer[512];
	int bytes = recv(client_fd, buffer, sizeof(buffer) - 1, 0); 

	if (bytes <= 0)
	{
		close(client_fd); 
		removeClient(client_fd);
	}
	else
	{
		buffer[bytes] = '\0'; 
		std::string received(buffer);
		_client_buffers[client_fd] += received;

		std::string &full_msg = _client_buffers[client_fd];
		size_t pos;

		std::cout << "Received message from client " << client_fd << ": " << full_msg << std::endl;
		while ((pos = full_msg.find("\n")) != std::string::npos)
		{
			std::string msg = full_msg.substr(0, pos); 
			full_msg.erase(0, pos + 1);
			if (!_client[client_fd].isAuth())
			{
				if (msg.compare(0, 4, "CAP ") == 0 || msg.compare(0, 5, "NICK ") == 0 || msg.compare(0, 5, "USER ") == 0) 
				{
					saveDefault(client_fd, msg);
					continue ;
				}
				if (msg.find("PASS ") == 0)
				{
					std::string pass = msg.substr(5);
					
					// Rimuovi spazi bianchi e newline alla fine della password
					pass.erase(pass.find_last_not_of(" \r\n") + 1);

					// Rimuovi il carattere ':' all'inizio della password, se presente
					if (!pass.empty() && pass[0] == ':')
						pass = pass.substr(1);

					std::cout << "Received password: [" << pass << "]" << std::endl;
					std::cout << "Expected password: [" << _password << "]" << std::endl;

					if (pass == _password)
					{
						_client[client_fd].setAuth(true);
						sendToClient(client_fd, "You are now authenticated!\n");
					}
					else
					{
						sendToClient(client_fd, "Invalid password! Try again!\n");
					}
				}
				else
					sendToClient(client_fd, "Please authenticate with PASS <password>\n");
			}
			else
				processCommand(client_fd, msg);
		}
	}
}

void Server::processCommand(int client_fd, const std::string &msg)
{
	std::istringstream iss(msg);
	std::string command;
	iss >> command;

	if (command == "JOIN")
		joinChannel(client_fd, msg);
	else if (command == "NICK")
	{
		std::string nick;
		iss >> nick;
		_client[client_fd].setNickname(nick);
		sendToClient(client_fd, "Your nickname has been set to " + nick + "\n");
	}
	else if (command == "USER")
	{
		std::string username, hostname, servername, realname;
		iss >> username >> hostname >> servername;
		std::getline(iss >> std::ws, realname);
		std::cout << "realname: " << realname << std::endl;
		if (realname[0] != ':')
		{
			sendToClient(client_fd, "Invalid message format. Usage: USER <username> <hostname> <servername> :<realname>\n");
			return ;
		}
		realname = realname.substr(1);
		_client[client_fd].setUsername(username);
		_client[client_fd].setHostname(hostname);
		_client[client_fd].setServername(servername);
		_client[client_fd].setRealname(realname);
		sendToClient(client_fd, "001 :User registration successful\r\n");
		std::cout << "Client " << client_fd << " has registered as " << username << std::endl;
	}
	else if (command == "PING")
	{
		std::string server;
		iss >> server;
		sendToClient(client_fd, "PONG " + server + "\n");
        std::cout << "Client " << client_fd << " sent PING, responding with PONG" << std::endl;
	}
	else if (command == "USERHOST")
	{
		std::string nick;
		iss >> nick;
		int fd = getClientFd(nick);
		if (fd != -1)
			sendToClient(client_fd, "302 " + nick + "=" + _client[fd].getNickname() + "@" + _client[fd].getHostname() + "\n");
		else
			sendToClient(client_fd, "401 " + nick + " :No such nick/channel\n");
	}
	else if (command == "PRIVMSG")
	{
		std::string target, message;
		iss >> target;
		std::getline(iss >> std::ws, message);
		if (message[0] != ':' || message[1] == '\0')
		{
			sendToClient(client_fd, "Invalid message format. Usage: <nickname/#channel> :<message>\n");
			return ;
		}

		message = message.substr(1);
		if (target[0] == '#')
		{
			std::string name = target.substr(1);
			if (!_channels[name].isMember(client_fd)) // Se il client non è già membro
				sendToClient(client_fd, ":localhost 404 " + target + " :You are not in the channel\r\n");
			else
			{
				std::vector<int> clients = _channels[name].getMembers();
				for (std::vector<int>::iterator it = clients.begin(); it != clients.end(); ++it)
				{
					if (*it != client_fd)
						sendToClient(*it, ":" + _client[client_fd].getNickname() + " PRIVMSG " + target + " " + message + "\r\n");
				}
			}
		}
		else
		{
			int fd = getClientFd(target);
			if (fd != -1)
				for (std::map<int, Client>::iterator it = _client.begin(); it != _client.end(); ++it)
				{
					if (it->second.getNickname() == target)
					{
						sendToClient(it->second.getFd(),  ":" + _client[client_fd].getNickname() + " PRIVMSG " + target + " " + message + "\r\n");
						break ;
					}
				}
			else
				sendToClient(client_fd, "401 " + target + " :No such nickname/channel\n");
		}
	}
	else if (command == "WHO")
	{
		std::string target;
		iss >> target;
		if (target[0] == '#')
			whoChannel(client_fd, target);
		else
			whoNick(client_fd, target);
	}
	else if (command == "PART")
		partChannel(client_fd, msg);
	else if (command == "INVITE")
		inviteChannel(client_fd, msg);
	else if (command == "KICK")
		kickChannel(client_fd, msg);
	else if (command == "TOPIC")
		topicChannel(client_fd, msg);
	else if (command == "MODE")
		modeChannel(client_fd, msg);
	else
		sendToClient(client_fd, "Invalid command\n");
}

void Server::closeServer()
{
    for (size_t i = 0; i < _clients.size(); i++)
	{
        close(_clients[i].fd);
    }
    close(_server_socket);
}


void Server::stop()
{
    _running = false; // Metodo per fermare il server
}
