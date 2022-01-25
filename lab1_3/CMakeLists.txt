cmake_minimum_required(VERSION 3.16)
project(lab1_3)

set(CMAKE_CXX_STANDARD 17)

add_executable(${CMAKE_PROJECT_NAME}_run

        sequence.h
        arraysequence.cpp
        arraysequence.h
        dynamicarray.cpp
        dynamicarray.h
        extrafunctions.h
        isorter.cpp
        isorter.h
        linkedlist.cpp
        linkedlist.h
        listsequence.cpp
        listsequence.h
        graphtests.h
        main.cpp)