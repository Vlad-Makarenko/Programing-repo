cmake_minimum_required(VERSION 3.17.3)
project(lab32)

set(CMAKE_CXX_STANDARD 11)

include_directories(src)
add_executable(lab32_main src/main.cpp src/Backpack.cpp src/Backpack.h src/Container.hpp)