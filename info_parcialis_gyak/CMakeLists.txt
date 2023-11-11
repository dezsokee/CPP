cmake_minimum_required(VERSION 3.26)
project(info_parcialis_gyak)

set(CMAKE_CXX_STANDARD 17)

add_executable(info_parcialis_gyak main.cpp
        Book.cpp
        Book.h
        Library.cpp
        Library.h)
