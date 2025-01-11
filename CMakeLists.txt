cmake_minimum_required(VERSION 3.30)
project(Heuristic_Optimization)

set(CMAKE_CXX_STANDARD 20)

add_executable(Heuristic_Optimization main.cpp
        ObjectiveFunction.cpp
        include/ObjectiveFunction.h
)
