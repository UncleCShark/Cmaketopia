# CMakeList.txt : HelloWord CMake project file
cmake_minimum_required (VERSION 3.8 FATAL_ERROR)

project("HelloWorld" LANGUAGES CXX)

add_executable(hello hello.cpp)