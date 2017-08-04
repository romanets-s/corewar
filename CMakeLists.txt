cmake_minimum_required(VERSION 3.7)
project(corewar)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c corewar.h)
add_executable(corewar ${SOURCE_FILES})