cmake_minimum_required(VERSION 3.26)
project(lab09_extra)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab09_extra main.cpp
        Account.cpp
        Account.h
        Customer.cpp
        Customer.h
        Bank.cpp
        Bank.h)
