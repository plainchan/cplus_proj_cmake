cmake_minimum_required(VERSION 3.5)

project(socket_usage)



add_executable(${PROJECT_NAME} src/main.cpp)

# simple case
add_executable(client src/simple_client.c)
add_executable(server src/simple_server.c)

# chat room
add_executable(chatroom_client src/epoll_chatroom_client.cpp)
add_executable(chatroom_server src/epoll_chatroom_server.cpp)


# IO multiplex
add_executable(mux_client src/mux_client.cpp)
add_executable(mux_server src/mux_server.cpp)


target_include_directories(${PROJECT_NAME}
    PRIVATE
    ${PROJECT_SOURCE_DIR}/include
)
target_include_directories(chatroom_client
    PRIVATE
    ${PROJECT_SOURCE_DIR}/include
)
target_include_directories(chatroom_server
    PRIVATE
    ${PROJECT_SOURCE_DIR}/include
)