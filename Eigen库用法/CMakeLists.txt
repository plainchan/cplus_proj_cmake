cmake_minimum_required(VERSION 3.5)

project(Eigen_usage)

find_package(Eigen3)
include_directories(${EIGEN3_INCLUDE_DIR})

add_executable(${PROJECT_NAME}  main.cpp)



