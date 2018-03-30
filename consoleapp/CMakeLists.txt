cmake_minimum_required(VERSION 3.4.1)

project(consoleapp)

add_executable(consoleapp main.cpp)
target_include_directories(consoleapp PRIVATE "../libraries/liboptions")
target_link_libraries(consoleapp options)
