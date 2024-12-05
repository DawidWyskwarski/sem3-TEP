cmake_minimum_required(VERSION 3.29)
project(laby4)

set(CMAKE_CXX_STANDARD 11)

add_executable(laby4
        ConsoleUserInterface.h
        ConsoleUserInterface.cpp
        Node.h
        Node.cpp
        Tree.h
        Tree.cpp
        main.cpp
        Error.cpp
        Error.h
        Result.h
        SaveResult.h
)



