cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_STANDARD 20)

project(HelloWorld)

add_executable(${PROJECT_NAME} src/main.cpp) 
target_include_directories(${PROJECT_NAME}
    PRIVATE 
        ${PROJECT_SOURCE_DIR}/include
)