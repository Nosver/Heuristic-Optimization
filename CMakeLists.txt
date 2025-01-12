cmake_minimum_required(VERSION 3.30)
project(Heuristic_Optimization)

set(CMAKE_CXX_STANDARD 20)

add_executable(Heuristic_Optimization src/main.cpp
        src/ObjectiveFunction.cpp
        include/ObjectiveFunction.h
        include/EvolutionaryAlgorithm.h
        include/utils.h
        src/utils.cpp
        src/EvolutionaryAlgorithm.cpp
)
