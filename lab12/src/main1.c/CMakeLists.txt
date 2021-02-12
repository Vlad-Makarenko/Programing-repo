cmake_minimum_required(VERSION 3.17)
project(main1_c C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(main1_c
        lib.c
        lib.h
        main.c)
