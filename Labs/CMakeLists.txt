cmake_minimum_required(VERSION 3.23)
project(Labs)

set(CMAKE_CXX_STANDARD 17)

add_executable(LAB_01
        LAB_01/main.cpp
        LAB_01/Employee/Employee.cpp
        LAB_01/Date/Date.cpp
        LAB_01/InputHelper/InputHelper.cpp
        LAB_01/InputHelper/InputHelper.h)

add_executable(LAB_02
        LAB_02/main.cpp LAB_02/String/String.cpp LAB_02/String/String.h)

add_executable(
        LAB_03
        LAB_03/main.cpp
        LAB_03/main.cpp LAB_03/Computer/Computer.cpp LAB_03/Computer/Computer.h LAB_03/Desktop/Desktop.cpp LAB_03/Desktop/Desktop.h LAB_03/Portable/Portable.cpp LAB_03/Portable/Portable.h LAB_03/Monoblock/Monoblock.cpp LAB_03/Monoblock/Monoblock.h LAB_03/Laptop/Laptop.cpp LAB_03/Laptop/Laptop.h LAB_03/Tablet/Tablet.cpp LAB_03/Tablet/Tablet.h LAB_03/Serializer/Serializer.cpp LAB_03/Serializer/Serializer.h)