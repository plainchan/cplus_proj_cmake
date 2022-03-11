cmake_minimum_required(VERSION 3.5)

project(dynamic_memory)

set(CMAKE_CXX_STANDARD 11)

add_executable(${PROJECT_NAME} src/main.cpp)

target_link_directories(${PROJECT_NAME}
    PRIVATE
    ${PROJECT_SOURCE_DIR}/include
)