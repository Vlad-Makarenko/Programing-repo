cmake_minimum_required(VERSION 3.17)
project(main2_c C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(main2_c
        lib.c
        lib.h
        main.c)
