cmake_minimum_required(VERSION 3.17)
project(lab28)

set(CMAKE_CXX_STANDARD 11)

include_directories(src)
add_executable(lab28_main src/main.cpp src/Task.cpp src/Task.h src/Menu.cpp src/Menu.h)
add_executable(lab28_test test/test.cpp src/Task.cpp src/Menu.cpp)