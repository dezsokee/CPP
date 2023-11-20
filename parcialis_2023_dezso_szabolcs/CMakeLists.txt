cmake_minimum_required(VERSION 3.26)
project(parcialis_2023_dezso_szabolcs)

set(CMAKE_CXX_STANDARD 17)

add_executable(parcialis_2023_dezso_szabolcs main.cpp
        Developer.cpp
        Developer.h
        Project.cpp
        Project.h
        Company.cpp
        Company.h)
