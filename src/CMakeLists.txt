add_executable(client client.cpp client_main.cpp)
add_executable(server server.cpp server_main.cpp)

target_include_directories (client
                PUBLIC ${CMAKE_THREAD_LIBS_INIT}
)

target_include_directories (server
                PUBLIC ${CMAKE_THREAD_LIBS_INIT}
)

