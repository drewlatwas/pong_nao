cmake_minimum_required(VERSION 3.6)
project(src)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        main.cpp
        MasterGui.cpp
        MasterGui.hpp)

add_executable(src ${SOURCE_FILES})