cmake_minimum_required(VERSION 3.3)
project(IP_PA_2_pa2_pa3)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    Cluster.cpp
    Cluster.h
    KMeans.cpp
    KMeans.h
    main.cpp
    Point.cpp
    Point.h)

add_executable(IP_PA_2_pa2_pa3 ${SOURCE_FILES})