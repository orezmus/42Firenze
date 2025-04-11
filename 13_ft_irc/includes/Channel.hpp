#ifndef CHANNEL_HPP
# define CHANNEL_HPP

# include <iostream>
# include <string>
# include <vector>
# include <map>
# include <sys/socket.h>
# include <algorithm>

# include "Client.hpp"

class Client;

class Channel
{
    private:
        std::string         _name;
        std::string         _topic;
        std::vector<int>    _members;
        std::vector<int>    _operators;
        std::vector<Client> _clients;
        int                 _limit;
        bool                _invite_only;
        bool                _restrictTopic;
        std::string         _key;

    public:
        Channel();
        Channel(const std::string &name);

        void                    setTopic(const std::string &topic);
        std::string             getTopic() const;
        std::string             getClientList(const std::map<int, std::string> &clientNicknames) const;

        void                    setMode(char mode, bool value);
        bool                    getMode(char mode) const;

        void                    setLimit(int limit);
        void                    setKey(const std::string &key);
        std::string             getKey() const;

        bool                    isInviteOnly() const;
        bool                    isFull() const;
        bool                    isRestrictedTopic() const;

        const std::vector<int>& getClients() const;
        bool                    addClient(int client_fd);
        bool                    removeClient(int client_fd);
        void                    addOperator(int client_fd);
        void                    removeOperator(int client_fd);

        const std::vector<int>  &getMembers() const;

        bool                    isMember(int client_fd) const;
        bool                    isOperator(int client_fd) const;

        bool                    isEmpty() const;
        void                    broadcast(const std::string& message);
};

#endif // CHANNEL_HPP