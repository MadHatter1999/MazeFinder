cmake_minimum_required(VERSION 3.14)
project(MazeFinder)

set(CMAKE_CXX_STANDARD 14)

add_executable(MazeFinder main.cpp StackNode.h StackNode.cpp Stack.h Stack.cpp)