cmake_minimum_required(VERSION 3.27)
project(linklistas)

set(CMAKE_CXX_STANDARD 17)

add_executable(linklistas main.cpp
        Nodo.cpp
        Nodo.h
        Lista.cpp
        Lista.h)
