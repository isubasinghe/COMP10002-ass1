cmake_minimum_required(VERSION 3.8)
project(ass1)

set(CMAKE_C_STANDARD 99)

set(CMAKE_C_FLAGS  "${CMAKE_C_FLAGS} -g")

set(SOURCE_FILES main.c)
add_executable(ass1 ${SOURCE_FILES})

target_link_libraries(ass1 m)