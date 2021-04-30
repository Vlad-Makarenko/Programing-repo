cmake_minimum_required(VERSION 3.17)
project(lab24)

set(CMAKE_CXX_STANDARD 11)

include_directories(src)
add_executable(lab25_main src/main.cpp src/Backpack.cpp src/Backpack.h src/Container.cpp src/Container.h)
add_executable(lab25_test test/test.cpp src/Backpack.cpp src/Container.cpp)