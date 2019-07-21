cmake_minimum_required(VERSION 3.13)
project(MyLeetCode)

set(CMAKE_CXX_STANDARD 14)

add_executable(MyLeetCode main.cpp MyLeetCode.cpp MyLeetCode.h
        insertDeleteGetRandomO1.h
        largestNumberAtLeastTwiceOfOthers.cpp
        triangle.cpp
        searchInsertPosition.cpp
        maximizeDistanceToClosestPerson.cpp
        setMatrixZeroes.cpp
        transformToChessboard.cpp
        maximumSwap.cpp
        maximumAverageSubarrayI.cpp
        findMinimumInRotatedSortedArray.cpp
        findMinimumInRotatedSortedArrayII.cpp
        removeDuplicatesFromSortedArray.cpp
        removeDuplicatesFromSortedArrayII.cpp
        globalAndLocalInversions.cpp
        subarrayProductLessThanK.cpp
        friendsOfAppropriateAges.cpp
        validParentheses.cpp
        decodeString.cpp
        constructBinaryTreeFromPreorderAndInorderTraversal.cpp
        constructBinaryTreeFromInorderAndPostorderTraversal.cpp
        implementTrie.h
        LRUCache.h
        addAndSearchWord.h
        sortArrayByParity.cpp
        sortArrayByParityII.cpp
        squaresOfASortedArray.cpp
        peakIndexInAMountainArray.cpp
        searchInRotatedSortedArray.cpp
        )