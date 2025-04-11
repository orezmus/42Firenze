#include "Server.hpp"

Server *serverPtr = NULL;

void handleSignal(int signal)
{
    std::cout << " Signal received: " << signal << std::endl;
    if (serverPtr)
        serverPtr->stop(); // Fermare il server
}

int main(int argc, char* argv[])
{
    if (argc != 3)
    {
        std::cerr << "Usage: " << argv[0] << " <port> <password>\n";
        return 1;
    }

    std::string port = argv[1];
    std::string password = argv[2];

    signal(SIGINT, handleSignal);
    Server server(port, password);
    server.run();

    return 0;
}