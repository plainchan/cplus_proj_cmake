cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_STANDARD 17)
project(exception)

add_executable(${PROJECT_NAME} main.cpp) 

target_include_directories(${PROJECT_NAME}
    PRIVATE
    ${PROJECT_SOURCE_DIR}/include
)