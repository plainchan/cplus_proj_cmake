cmake_minimum_required(VERSION 3.5)
project(class_StaticFunc_usage)
add_executable(${PROJECT_NAME}  src/main.cpp )

target_include_directories(${PROJECT_NAME}
  PRIVATE
    ${PROJECT_SOURCE_DIR}/include 
)