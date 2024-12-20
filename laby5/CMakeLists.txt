cmake_minimum_required(VERSION 3.29)
project(laby5)

set(CMAKE_CXX_STANDARD 11)

add_executable(laby5
        RefCounter.h
        MySmartPointer.h
        Node.h
        Node.cpp
        Tree.h
        Tree.cpp
        Error.cpp
        Error.h
        Result.h
        main.cpp
)
