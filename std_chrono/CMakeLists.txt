cmake_minimum_required(VERSION 3.5)

project(std_chrono)

add_executable(${PROJECT_NAME} src/main.cpp)



target_include_directories(${PROJECT_NAME}
    PRIVATE include
)

