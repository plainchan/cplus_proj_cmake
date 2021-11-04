cmake_minimum_required(VERSION 3.5)

project(inline_keyword)

add_executable(${PROJECT_NAME}   src/main.cpp  src/example.cpp)

target_include_directories(${PROJECT_NAME}
    PRIVATE
    ${PROJECT_SOURCE_DIR}/include
)