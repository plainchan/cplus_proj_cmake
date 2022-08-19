cmake_minimum_required(VERSION 3.5)

project(Eigen_usage)

find_package(Eigen3)

add_executable(${PROJECT_NAME}  src/main.cpp)

target_include_directories(${PROJECT_NAME}
    PRIVATE 
    ${EIGEN3_INCLUDE_DIR}
    ${PROJECT_NAME}/include
)

# 因为Eigen库是基于模板实现的，使用的是源码，编译并不会生成动态库或静态库。
# target_link_libraries()

