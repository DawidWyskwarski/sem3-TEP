cmake_minimum_required(VERSION 3.29)
project(laby3)

set(CMAKE_CXX_STANDARD 11)

add_executable(laby3 main.cpp
        Tree.cpp
        Tree.h
        Node.cpp
        Node.h
        ConsoleUserInterface.cpp
        ConsoleUserInterface.h)
