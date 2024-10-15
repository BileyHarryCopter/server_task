#include "server.hpp"
#include <iostream>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

Server::Server(int port) : port(port), server_fd(-1) 
{
    log_file.open("log.txt", std::ios::app);
    if (!log_file.is_open()) 
    {
        std::cerr << "Failed to open log file" << std::endl;
        exit(1);
    }
}

void Server::run() 
{
    setupServer();
    acceptClients();
}

void Server::setupServer() 
{
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) 
    {
        std::cerr << "Failed to create socket" << std::endl;
        exit(1);
    }

    sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);

    if (bind(server_fd, (struct sockaddr*)&address, sizeof(address)) < 0) 
    {
        std::cerr << "Bind failed" << std::endl;
        exit(1);
    }

    if (listen(server_fd, 3) < 0) 
    {
        std::cerr << "Listen failed" << std::endl;
        exit(1);
    }

    std::cout << "Server listening on port " << port << std::endl;
}

void Server::acceptClients() 
{
    while (true) 
    {
        sockaddr_in client_address;
        socklen_t addrlen = sizeof(client_address);
        int client_socket = accept(server_fd, (struct sockaddr*)&client_address, &addrlen);
        
        if (client_socket < 0) 
        {
            std::cerr << "Accept failed" << std::endl;
            continue;
        }

        client_threads.emplace_back(&Server::handleClient, this, client_socket);
    }
}

void Server::handleClient(int client_socket) 
{
    char buffer[1024] = {0};
    int valread = read(client_socket, buffer, 1024);
    if (valread > 0) 
    {
        std::string message(buffer);
        writeToLog(message);
    }
    close(client_socket);
}

void Server::writeToLog(const std::string& message) 
{
    std::lock_guard<std::mutex> lock(file_mutex);
    log_file << message;
    log_file.flush();
}
