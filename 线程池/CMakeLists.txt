cmake_minimum_required(VERSION 3.5)

project(thread_pool)

find_package(Threads REQUIRED)

add_executable(${PROJECT_NAME} src/main.cpp )

target_link_libraries(${PROJECT_NAME} PUBLIC Threads::Threads)

target_include_directories(${PROJECT_NAME} 
    PRIVATE
    ${CMAKE_SOURCE_DIR}/include
)
