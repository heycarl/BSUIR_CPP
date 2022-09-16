cmake_minimum_required(VERSION 3.23)
project(Labs)

set(CMAKE_CXX_STANDARD 17)

add_executable(LAB_01
        LAB_01/main.cpp
        LAB_01/Employee/Employee.cpp
        LAB_01/Date/Date.cpp
        LAB_01/InputHelper/InputHelper.cpp
        LAB_01/InputHelper/InputHelper.h)