cmake_minimum_required(VERSION 3.29)
project(mini_project)

set(CMAKE_CXX_STANDARD 26)

add_executable(mini_project
        GaussianGroupingEvaluatorFactory.cpp
        GroupingChallenge.cpp
        GroupingEvaluator.cpp
        Optimizer.cpp
        Point.cpp)
