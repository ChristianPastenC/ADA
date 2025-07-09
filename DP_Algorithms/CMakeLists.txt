cmake_minimum_required(VERSION 3.31)
project(DP_Algorithms)

set(CMAKE_CXX_STANDARD 20)

add_executable(DP_Algorithms main.cpp
        KnapsackSolver.cpp
        KnapsackSolver.h
        RodCutter.cpp
        RodCutter.h
        MatrixChain.cpp
        MatrixChain.h)
