cmake_minimum_required(VERSION 3.16.3)
project(lab30)

set(CMAKE_CXX_STANDARD 11)

include_directories(src)
add_executable(lab30_main src/main.cpp src/Backpack.cpp src/Backpack.h src/Container.cpp src/Container.h)
add_executable(lab30_test test/test.cpp src/Backpack.cpp src/Container.cpp)