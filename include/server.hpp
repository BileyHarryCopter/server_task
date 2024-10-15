#pragma once

#include <string>
#include <thread>
#include <vector>
#include <mutex>
#include <fstream>

class Server 
{
public:
    Server(int port);
    void run();

private:
    int port;
    int server_fd;
    std::vector<std::thread> client_threads;
    std::mutex file_mutex;
    std::ofstream log_file;

    void setupServer();
    void acceptClients();
    void handleClient(int client_socket);
    void writeToLog(const std::string& message);
};
