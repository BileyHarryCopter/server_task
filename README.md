# Client-Server Application

This is a simple client-server application implemented in C++. It consists of a server that accepts connections from clients and writes the received messages to **log.txt**.

## Requirements:

- C++11 compatible compiler (e.g., GCC 4.8.1 or higher)
- POSIX-compatible operating system (Linux, macOS)
- CMake

## Building

* The build is done using **cmake**:
    ```cpp
    cmake -B build
    cmake --build build
    ```

## Running and Operating the Program

* After building the project, you can find the executable files: **server** and **client** in the **build/src/** directory. The log report will be generated in the same directory.
