cmake_minimum_required(VERSION 3.29)
project(5 C)

set(CMAKE_C_STANDARD 99)

add_executable(5 main.c
        sort_method.h
        "customization .h"
        array_validation.h
)
