#ifndef CLIENT_HPP
# define CLIENT_HPP

# include <iostream>
# include <string>
# include <vector>
# include <poll.h>
# include <unistd.h>
# include <sys/socket.h>

class Client
{
    private:
        int         _fd;
        bool        _auth;
        std::string _username;
        std::string _nickname;
        std::string _hostname;
        std::string _servername;
        std::string _realname;

    public:
        Client();
        Client(int fd);
        ~Client();

        int                 getFd() const;
        bool                isAuth() const;
        const std::string   &getUsername() const;
        const std::string   &getNickname() const;
        const std::string   &getHostname() const;
        const std::string   &getServername() const;
        const std::string   &getRealname() const;
        void                setFd(int fd);
        void                setAuth(bool auth);
        void                setNickname(const std::string &nickname);
        void                setUsername(const std::string &username);
        void                setHostname(const std::string &hostname);
        void                setServername(const std::string &servername);
        void                setRealname(const std::string &realname);
};

#endif // CLIENT_HPP