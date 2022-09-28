cmake_minimum_required(VERSION 3.5)

project(multi_threading)

find_package(Threads REQUIRED )

set(CMAKE_CXX_STANDARD 20)

add_executable(${PROJECT_NAME} src/main.cpp )


target_link_libraries(${PROJECT_NAME} PUBLIC Threads::Threads)


target_include_directories(${PROJECT_NAME}
    PRIVATE 
        ${PROJECT_SOURCE_DIR}/include
)