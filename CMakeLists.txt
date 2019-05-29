cmake_minimum_required(VERSION 3.13)
project(MyLeetCode)

set(CMAKE_CXX_STANDARD 14)

add_executable(MyLeetCode main.cpp MyLeetCode.cpp MyLeetCode.h
        RandomizedSet.h constructBinaryTreeFromPreorderAndInorderTraversal.cpp
        largestNumberAtLeastTwiceOfOthers.cpp triangle.cpp
        searchInsertPosition.cpp maximizeDistanceToClosestPerson.cpp
        setMatrixZeroes.cpp transformToChessboard.cpp MaximumSwap.cpp
        maximumAverageSubarrayI.cpp
        findMinimumInRotatedSortedArray.cpp findMinimumInRotatedSortedArrayII.cpp
        removeDuplicatesFromSortedArray.cpp removeDuplicatesFromSortedArrayII.cpp
        globalAndLocalInversions.cpp subarrayProductLessThanK.cpp)