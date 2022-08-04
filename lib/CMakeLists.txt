cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/..)
project(TGoL VERSION 0.1)
configure_file(TGoLConfig.h.in TGoLConfig.h)
add_executable(TGoL Source.cpp Node.cpp Interface.cpp)
target_include_directories(TGoL PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           )