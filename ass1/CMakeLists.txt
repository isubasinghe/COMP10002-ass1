cmake_minimum_required(VERSION 3.8)
project(ass1)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c mystdio.h queries.h scoring.h myctypes.h mystrings.h)
add_executable(ass1 ${SOURCE_FILES})