cmake_minimum_required(VERSION 3.5)

project(compile_PIMPL)

add_executable(${PROJECT_NAME}   src/main.cpp  src/example.cpp  src/base.cpp)

target_include_directories(${PROJECT_NAME}
    PRIVATE
    ${PROJECT_SOURCE_DIR}/include
)