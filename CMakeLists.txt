# Copyright (C) 2017, Yeolar

cmake_minimum_required(VERSION 2.8.8)

project(AlgorithmExercises)

set(CMAKE_C_COMPILER gcc)
set(CMAKE_CXX_COMPILER g++)

set(CMAKE_THREAD_PREFER_PTHREAD TRUE)
find_package(Threads REQUIRED)
find_package(GTest)

set(CMAKE_BUILD_TYPE Release)
set(CMAKE_VERBOSE_MAKEFILE OFF)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O3 -std=c++11 -fPIC")

set(SRCS
    01_AssignmentOperator.cpp
    03_FindInPartiallySortedMatrix.cpp
    04_ReplaceBlank.cpp
    05_PrintListInReversedOrder.cpp
    06_ConstructBinaryTree.cpp
    07_QueueWithTwoStacks.cpp
    08_MinNumberInRotatedArray.cpp
    09_Fibonacci.cpp
    10_NumberOf1InBinary.cpp
    11_Power.cpp
)

enable_testing()

foreach(src ${SRCS})
    get_filename_component(filename ${src} NAME_WE)
    set(test ${filename})
    add_executable(${test} ${src})
    target_link_libraries(${test} ${GTEST_BOTH_LIBRARIES} ${GMOCK_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})
    add_test(${test} ${test} CONFIGURATIONS Debug)
endforeach()
