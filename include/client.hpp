#pragma once

#include <string>
#include "common.hpp"

class Client 
{
public:
    Client(const std::string& name, int port, int period);
    void run();

private:
    std::string name;
    int port;
    int period;
    int sock;

    void connectToServer();
    void sendMessage();
};
