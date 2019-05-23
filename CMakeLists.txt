cmake_minimum_required(VERSION 3.13)
project(MyLeetCode)

set(CMAKE_CXX_STANDARD 14)

add_executable(MyLeetCode main.cpp MyLeetCode.cpp MyLeetCode.h
        RandomizedSet.h constructBinaryTreeFromPreorderAndInorderTraversal.cpp
        removeDuplicatesFromSortedArray.cpp largestNumberAtLeastTwiceOfOthers.cpp
        searchInsertPosition.cpp maximizeDistanceToClosestPerson.cpp
        setMatrixZeroes.cpp transformToChessboard.cpp
        MaximumSwap.cpp)