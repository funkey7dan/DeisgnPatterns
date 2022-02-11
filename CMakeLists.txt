cmake_minimum_required(VERSION 3.21)
project(ap4test)

set(CMAKE_CXX_STANDARD 11)

add_executable(ap4test main.cpp composite.h decorator.h factory.h)
