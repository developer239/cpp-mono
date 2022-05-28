cmake_minimum_required(VERSION 3.22)
project(cpp_mono)

set(CMAKE_CXX_STANDARD 20)

add_executable(cpp_mono src/main.cpp src/loop/Loop.cpp src/loop/Loop.h)
