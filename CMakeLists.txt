cmake_minimum_required(VERSION 3.10)
project(tbSTL)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g") 

add_subdirectory(BreadestFirstSearch)

add_subdirectory(SlidingWindow)

add_subdirectory(PreNumsSum)

add_subdirectory(BinarySearch)

add_subdirectory(String)

add_subdirectory(Matrix)

add_subdirectory(MonoStack)

add_subdirectory(Array)

add_subdirectory(UnionFindSet)

add_subdirectory(BackTrack)

add_subdirectory(DynamicProgramming)