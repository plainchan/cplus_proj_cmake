cmake_minimum_required(VERSION 3.5)

project(keyboard_scan)

add_executable(${PROJECT_NAME} src/main  src/keyboard_scan.cpp)

target_include_directories(${PROJECT_NAME}
  PRIVATE
    ${PROJECT_SOURCE_DIR}/include
)
