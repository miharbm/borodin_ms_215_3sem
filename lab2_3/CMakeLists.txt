cmake_minimum_required(VERSION 3.16)
project(lab1_3)

set(CMAKE_CXX_STANDARD 17)

add_executable(${CMAKE_PROJECT_NAME}_run
        main.cpp

        Dict/Dict.hpp
        Dict/DictList.hpp Dict/DictNode.hpp
        Dict/DictNodeList.h
        Hist.hpp
        Dict/Idictionary.hpp

        sort.hpp
        )