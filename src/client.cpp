#include "client.hpp"
#include <iostream>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

Client::Client(const std::string& name, int port, int period)
    : name(name), port(port), period(period), sock(-1) {}

void Client::run() 
{
    while (true) 
    {
        connectToServer();
        sendMessage();
        close(sock);
        sleep(period);
    }
}

void Client::connectToServer() 
{
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) 
    {
        std::cerr << "Failed to create socket" << std::endl;
        exit(1);
    }

    sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) 
    {
        std::cerr << "Connection failed" << std::endl;
        exit(1);
    }
}

void Client::sendMessage() 
{
    std::string message = getCurrentTimestamp() + " " + name + "\n";
    if (send(sock, message.c_str(), message.length(), 0) < 0)
    {
        std::cerr << "Send failed" << std::endl;
        exit(1);
    }
}
