cmake_minimum_required(VERSION 3.6)
project(Pokemon_Strategy_tools)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c11")

set(SOURCE_FILES main.c LinkedList.c)
set(HEADER_FILES LinkedList.h)
add_executable(Pokemon_Strategy_tools ${SOURCE_FILES})