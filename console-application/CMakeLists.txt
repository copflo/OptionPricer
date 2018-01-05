cmake_minimum_required(VERSION 3.10)

add_executable(consoleapp main.cpp)
include_directories(../include)
target_link_libraries(consoleapp options)