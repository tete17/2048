cmake_minimum_required(VERSION 3.7)
project(2048)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp gameOf2048.cpp cell.cpp)
add_executable(2048 ${SOURCE_FILES})