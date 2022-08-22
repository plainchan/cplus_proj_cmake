cmake_minimum_required(VERSION 3.11)

project(spdlog_test)

find_package(Threads REQUIRED)


############################################################
# Create spdlog library
############################################################
add_library(spdlog INTERFACE)
target_compile_features(spdlog INTERFACE
  cxx_std_11
)
target_link_libraries(spdlog INTERFACE Threads::Threads)
target_include_directories(spdlog
    INTERFACE  
    ${PROJECT_SOURCE_DIR}/third-party/
)
############################################################
# spdlog library
############################################################


add_executable(${PROJECT_NAME}  src/main.cpp)

target_link_libraries(${PROJECT_NAME} spdlog)

target_include_directories(${PROJECT_NAME}
    PRIVATE  
    ${PROJECT_SOURCE_DIR}/include 
)

