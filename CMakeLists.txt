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
    12_Print1ToMaxOfNDigits.cpp
    13_DeleteNodeInList.cpp
    14_ReorderArray.cpp
    15_KthNodeFromEnd.cpp
    16_ReverseList.cpp
    17_MergeSortedLists.cpp
    18_SubstructureInTree.cpp
    19_MirrorOfBinaryTree.cpp
    21_MinInStack.cpp
    22_StackPushPopOrder.cpp
    23_PrintTreeFromTopToBottom.cpp
    38_NumberOfK.cpp
    39_1_TreeDepth.cpp
    39_2_BalancedBinaryTree.cpp
    40_NumbersAppearOnce.cpp
    49_StringToInt.cpp
    50_CommonParentInTree.cpp
)

enable_testing()

foreach(src ${SRCS})
    get_filename_component(filename ${src} NAME_WE)
    set(test ${filename})
    add_executable(${test} ${src})
    target_link_libraries(${test} ${GTEST_BOTH_LIBRARIES} ${GMOCK_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})
    add_test(${test} ${test} CONFIGURATIONS Debug)
endforeach()
