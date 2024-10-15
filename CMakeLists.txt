cmake_minimum_required(VERSION 3.8)

project(Server_task
        LANGUAGES CXX)

set (CMAKE_CXX_STANDARD 20)

find_package (Threads REQUIRED)

set(CMAKE_CXX_STANDARD          20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS        OFF)

include_directories(./include/)

add_subdirectory(src)
