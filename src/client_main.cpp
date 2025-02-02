#include "client.hpp"
#include <iostream>

int main(int argc, char* argv[]) 
{
    if (argc != 4) 
    {
        std::cerr << "Usage: " << argv[0] << " <name> <port> <period>" << std::endl;
        return 1;
    }

    std::string name = argv[1];
    int port = std::stoi(argv[2]);
    int period = std::stoi(argv[3]);

    Client client(name, port, period);
    client.run();

    return 0;
}