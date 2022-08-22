cmake_minimum_required(VERSION 3.5)

project(socket_usage LANGUAGES C)



add_executable(client src/simple_client.c)
add_executable(server src/simple_server.c)



# target_link_directories(${PROJECT_NAME}
#     PRIVATE
#     ${PROJECT_SOURCE_DIR}/include
# )