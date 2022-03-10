cmake_minimum_required(VERSION 3.8)

project(plt)

find_package(Python3 COMPONENTS Interpreter Development NumPy REQUIRED)

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE
  Python3::Python
#   Python3::Module
#   Python3::NumPy
)


 





