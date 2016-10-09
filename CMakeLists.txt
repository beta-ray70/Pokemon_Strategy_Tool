cmake_minimum_required(VERSION 3.6)
project(src)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c11")

set(SOURCE_FILES src/main.c src/LinkedList.c)
set(HEADER_FILES include/LinkedList.h)
add_executable(src ${SOURCE_FILES})