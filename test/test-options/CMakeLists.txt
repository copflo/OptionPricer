cmake_minimum_required(VERSION 3.1.0)

add_library(gtest STATIC IMPORTED)
set_target_properties(gtest PROPERTIES IMPORTED_LOCATION ${CMAKE_BINARY_DIR}/lib/libgtest.a)

add_executable(testoptions main.cpp)
include_directories(../../include)
target_link_libraries(testoptions options gtest)



