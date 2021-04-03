cmake_minimum_required(VERSION 3.17)
project(lab19 C)

set(CMAKE_C_STANDARD 11)

include_directories(src)
add_executable(lab19_main src/main.c src/data.h src/list.h src/list.c src/data.c)
add_executable(lab19_test test/test.c src/list.c src/data.c)