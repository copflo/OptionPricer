cmake_minimum_required(VERSION 3.4.1)

project(consoleapp)

add_executable(consoleapp main.cpp)
include_directories(../include)
target_link_libraries(consoleapp options)
