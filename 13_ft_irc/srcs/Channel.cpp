#include "Channel.hpp"

Channel::Channel()
{
    _name = "";
    _topic ="";
    _limit = -1;
    _invite_only = false;
    _restrictTopic = false;
}

Channel::Channel(const std::string &name)
{
    _name = name;
    _topic ="";
    _limit = -1;
    _invite_only = false;
    _restrictTopic = false;
}

void Channel::setMode(char mode, bool value)
{
    switch (mode)
    {
        case 'i':
            _invite_only = value;
            break;
        case 't':
            _restrictTopic = value;
            break;
        default:
            break;
    }  
}

bool Channel::getMode(char mode) const
{
    switch (mode)
    {
        case 'i':
            return _invite_only;
        case 't':
            return _restrictTopic;
        default:
            return false;
    }
}

void Channel::setLimit(int limit)
{
    _limit = limit;
}

void Channel::setTopic(const std::string &topic)
{
    _topic = topic;
}

std::string Channel::getTopic() const 
{
    return _topic;
}

std::string Channel::getClientList(const std::map<int, std::string>& clientNicknames) const
{
    std::string client_list;

    for (std::vector<int>::const_iterator it = _members.begin(); it != _members.end(); ++it)
    {
        if (!client_list.empty())
            client_list += " ";  // Aggiungi uno spazio tra i nickname

        std::map<int, std::string>::const_iterator nickIt = clientNicknames.find(*it);
        if (nickIt != clientNicknames.end())
            client_list += nickIt->second;  // Usa il nickname trovato nella mappa
        else
            // Gestisci il caso in cui il file descriptor non è trovato nella mappa
            // Ad esempio, puoi aggiungere un placeholder o gestire l'errore
            client_list += "[unknown]";  // Placeholder per clienti sconosciuti
    }
    return client_list;
}

void Channel::setKey(const std::string &key)
{
    _key = key;
}

std::string Channel::getKey() const
{
    return _key;
}

bool Channel::isInviteOnly() const
{
    return _invite_only;
}

bool Channel:: isFull() const
{
    return _limit == static_cast<int>(_members.size());
}

bool Channel::isRestrictedTopic() const
{
    return _restrictTopic;
}  

bool Channel::addClient(int client_fd)
{
    if (_members.size() < static_cast<size_t>(_limit) || _limit == -1)
    {    
        _members.push_back(client_fd);
        std::cout << "Client " << client_fd << " is added to channel\n";
        return true;
    }
    return false;
}

bool Channel::removeClient(int client_fd)
{
    std::vector<int>::iterator it;
    for (it = _members.begin(); it != _members.end(); ++it) 
    {
        if (*it == client_fd) 
        {        
            _members.erase(it);
            return true;
        }
    }
    return false;
}

bool Channel::isMember(int client_fd) const
{
    for (size_t i = 0; i < _members.size(); i++)
    {
        if (_members[i] == client_fd)
            return true;  // 클라이언트가 채널 멤버임을 반환
    }
    return false;  // 클라이언트가 채널 멤버가 아님을 반환
}


void Channel::addOperator(int client_fd)
{
    std::vector<int>::iterator it;
    for (it = _operators.begin(); it != _operators.end(); ++it) 
    {
        if (*it == client_fd)
            return ;
    }
    _operators.push_back(client_fd);
}

void Channel::removeOperator(int client_fd)
{
    std::vector<int>::iterator it;
    for (it = _operators.begin(); it != _operators.end(); ++it) 
    {
        if (*it == client_fd) 
        {
            _operators.erase(it);
            return ;
        }
    }
}

bool Channel::isOperator(int client_fd) const
{
    std::vector<int>::const_iterator it;
    for (it = _operators.begin(); it != _operators.end(); ++it) 
    {
        if (*it == client_fd) 
            return true;
    }
    return false;
}

const std::vector<int> &Channel::getMembers() const
{
    return _members;
}

// Restituisce true se il canale è vuoto, altrimenti false
bool Channel::isEmpty() const
{
	return _members.empty(); // Verifica se la mappa è vuota
}

void Channel::broadcast(const std::string& message)
{
    std::vector<int>::const_iterator it;
    for (it = _members.begin(); it != _members.end(); ++it) 
    {
        int client_fd = *it;
        send(client_fd, message.c_str(), message.length(), 0);
    }
}