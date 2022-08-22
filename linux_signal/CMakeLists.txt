cmake_minimum_required(VERSION 3.10)

project(linux_signal)

add_executable(${PROJECT_NAME}  src/main.cpp)

target_include_directories(${PROJECT_NAME}
    PRIVATE  
    include
)

