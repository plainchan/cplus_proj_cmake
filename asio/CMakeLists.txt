cmake_minimum_required(VERSION 3.5)


project(HelloWorld)

find_package(Threads REQUIRED)

set(CMAKE_CXX_STANDARD 11)

add_executable(${PROJECT_NAME} src/main.cpp) 
target_include_directories(${PROJECT_NAME}
    PRIVATE 
    include
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE 
    Threads::Threads
 
)