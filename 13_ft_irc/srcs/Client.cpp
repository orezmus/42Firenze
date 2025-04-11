#include "Client.hpp"

Client::Client()
{
    _fd = -1;
    _auth = false;
    _username = "";
    _nickname = "";
    _hostname = "";
    _realname = "";
}

Client::Client(int fd)
{
    _fd = fd;
    _auth = false;
    _username = "";
    _nickname = "";
    _hostname = "";
    _realname = "";
}

Client::~Client() {}

int Client::getFd() const
{
    return _fd;
}

bool Client::isAuth() const
{
    return _auth;
}

const std::string& Client::getUsername() const
{
    return _username;
}

const std::string& Client::getNickname() const
{
    return _nickname;
}

const std::string& Client::getHostname() const
{
    return _hostname;
}

const std::string& Client::getServername() const
{
    return _servername;
}

const std::string& Client::getRealname() const
{
    return _realname;
}

void Client::setFd(int fd)
{
    _fd = fd;
}

void Client::setAuth(bool auth)
{
    _auth = auth;
}   

void Client::setNickname(const std::string &nickname)
{
    _nickname = nickname;
}

void Client::setUsername(const std::string &username)
{
    _username = username;
}

void Client::setHostname(const std::string &hostname)
{
    _hostname = hostname;
}

void Client::setServername(const std::string &servername)
{
    _servername = servername;
}

void Client::setRealname(const std::string &realname)
{
    _realname = realname;
}
