cmake_minimum_required(VERSION 3.3)
project(IP_PA_2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    Cluster.cpp
    Cluster.h
    CMakeLists.txt
    main.cpp
    Point.cpp
    Point.h KMeans.cpp KMeans.h DimensionalityMismatchEx.cpp DimensionalityMismatchEx.h OutOfBoundsEx.cpp OutOfBoundsEx.h RemoveFromEmptyEx.cpp RemoveFromEmptyEx.h ZeroClustersEx.cpp ZeroClustersEx.h)

add_executable(IP_PA_2 ${SOURCE_FILES})