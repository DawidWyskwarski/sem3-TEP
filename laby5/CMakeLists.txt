cmake_minimum_required(VERSION 3.29)
project(laby5)

set(CMAKE_CXX_STANDARD 11)

add_executable(laby5 main.cpp
        MySmartPointer.h
        RefCounter.h)
