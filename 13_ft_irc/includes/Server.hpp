#ifndef SERVER_HPP
# define SERVER_HPP

# include <iostream>
# include <sstream>
# include <string>
# include <cstring>
# include <vector>
# include <poll.h>
# include <map>
# include <unistd.h>
# include <sys/socket.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <fcntl.h>
# include <cstdlib>
# include <algorithm>
# include <utility>
# include <csignal>

# include "Channel.hpp"
# include "Client.hpp"

class Server
{
	private:
		std::string						_port;
		std::string						_password;
		int								_server_socket;;

		std::vector<pollfd>				_clients;
		std::map<int, Client>			_client;
		std::map<int, std::string>		_client_buffers;
		
		std::map<std::string, Channel>	_channels;
		std::map<int, std::string>		_clientNicknames; // Dove int è l'ID del cliente e std::string è il nickname
		bool							_running;



		void    	setupServer();
		void    	handleConnetions();
		void		closeServer();


		void    	handleClient(int client_fd);
		void		removeClient(int client_fd);
		void		saveDefault(int client_fd, const std::string &msg);
		
		int			getClientFd(const std::string &name);
		std::string	getClientList(const std::map<int, std::string>& clientNicknames);
		Client*		getClient(int fd);
		void 		sendChannelListToClient(int client_fd, const std::string &channel_name);
		std::string getServerName() const;
		


		void		processCommand(int client_fd, const std::string &msg);
		void		operatorCommand(int client_fd, const std::string &msg);
		void    	sendToClient(int client_fd, const std::string &msg);
		void		broadcast(const std::string &channel_name, const std::string &msg);	
		
		void		joinChannel(int client_fd, const std::string &chanel_name);
		void		sendChannelToClient(int client_fd);
		void		partChannel(int client_fd, const std::string &msg);
		void		whoChannel(int client_fd, const std::string &channel_name);
		void		whoNick(int client_fd, const std::string &nickname);
		void		inviteChannel(int client_fd, const std::string &msg);
		void		kickChannel(int client_fd, const std::string &msg);
		void    	topicChannel(int client_fd, const std::string &msg);
		void		modeChannel(int client_fd, const std::string &msg);
		
		int			checkChannel(int client_fd, const std::string &channel_name);
		
		std::vector<std::string> findChannel(int client_fd) ;

		struct IsClientFd
		{
			int _client_fd;
			IsClientFd(int fd) : _client_fd(fd) {}
			bool operator()(const pollfd &pfd) const
			{
				return pfd.fd == _client_fd;
			}
		};
	public:
		Server(const std::string &port, const std::string &password);
		~Server();

		void    run();
		void	stop();
};

#endif // SERVER_HPP
