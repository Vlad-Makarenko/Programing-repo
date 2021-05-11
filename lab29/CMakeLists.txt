cmake_minimum_required(VERSION 3.17)
project(lab29)

set(CMAKE_CXX_STANDARD 11)

include_directories(src)
add_executable(lab29_main src/main.cpp src/Backpack.cpp src/Backpack.h src/list.hpp)
add_executable(lab29_test test/test.cpp src/Backpack.cpp src/list.hpp)