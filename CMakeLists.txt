cmake_minimum_required(VERSION 3.26)
project(lifap)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)

add_executable(lifap
        SaveManager.cpp
        SaveManager.h
        Save.cpp
        Save.h
        Save.h
        main.cpp)
