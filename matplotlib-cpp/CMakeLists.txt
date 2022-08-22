cmake_minimum_required(VERSION 3.8)

project(plt LANGUAGES CXX)

find_package(Python3 COMPONENTS Interpreter Development REQUIRED)




############################################################
# Create matplotlibcpp library
############################################################
add_library(matplotlibcpp INTERFACE)
target_compile_features(matplotlibcpp INTERFACE
  cxx_std_11
)
target_link_libraries(matplotlibcpp INTERFACE
  Python3::Python
  Python3::Module
)
target_include_directories(matplotlibcpp
    INTERFACE  
    ${PROJECT_SOURCE_DIR}/third-party
)

find_package(Python3 COMPONENTS NumPy)
if(Python3_NumPy_FOUND)
  target_link_libraries(matplotlibcpp INTERFACE
    Python3::NumPy
  )
else()
  target_compile_definitions(matplotlibcpp INTERFACE WITHOUT_NUMPY)
endif()
############################################################
# matplotlibcpp library
############################################################




add_executable(${PROJECT_NAME} src/main.cpp)

target_link_libraries(${PROJECT_NAME} 
  PRIVATE
  matplotlibcpp
)
target_include_directories(${PROJECT_NAME}
  PRIVATE
  ${PROJECT_SOURCE_DIR}/include
)





 





