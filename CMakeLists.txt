cmake_minimum_required(VERSION 3.30)
project(untitled)

set(CMAKE_CXX_STANDARD 20)

add_executable(untitled main.cpp
        cBook.cpp
        cBook.h
        cLibrary.cpp
        cLibrary.h
        cMember.cpp
        cMember.h
        cData.cpp
        cData.h
        cUserInterface.cpp
        cUserInterface.h)
