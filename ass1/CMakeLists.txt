cmake_minimum_required(VERSION 3.8)
project(ass1)

set(CMAKE_C_STANDARD 90)

set(CMAKE_C_FLAGS  "${CMAKE_C_FLAGS} -Wall")

set(SOURCE_FILES main.c mystdio.h queries.h myctypes.h mystrings.h)
add_executable(ass1 ${SOURCE_FILES})

target_link_libraries(ass1 m)