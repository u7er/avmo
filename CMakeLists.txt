cmake_minimum_required(VERSION 3.8)
project(avmo)

set(CMAKE_CXX_STANDARD 14)


# Lab 1+
set(SOURCE_FILES
        "1+ Gauss on fraction/lab1plus.cpp"
        "1+ Gauss on fraction/Fraction.cpp"
        "1+ Gauss on fraction/Fraction.h"
        )
add_executable(lab1+ ${SOURCE_FILES})


# Lab 1
set(SOURCE_FILES
        "1. Gauss/gauss.cpp"
        )
add_executable(lab2 ${SOURCE_FILES})