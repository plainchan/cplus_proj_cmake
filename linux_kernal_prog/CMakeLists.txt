cmake_minimum_required(VERSION 3.10)

project(linux_kernal_prog)

add_executable(child_exec  src/child_exec.cpp)

add_executable(${PROJECT_NAME}  src/main.cpp)
add_dependencies(${PROJECT_NAME}  child_exec)

target_include_directories(${PROJECT_NAME}
    PRIVATE  
    include
)
target_link_libraries(${PROJECT_NAME}
    PRIVATE  
    pthread
)

