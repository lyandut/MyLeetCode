//
// Created by liyan on 2019-06-11.
//

/*
 * 852. Peak Index in a Mountain Array
 * https://leetcode.com/problems/peak-index-in-a-mountain-array/
 */

#include "MyLeetCode.h"

int MyLeetCode::peakIndexInMountainArray(vector<int> &A) {
    int left = 0, right = A.size() - 1;
    int mid;
    while(left < right) {
        mid = (left + right) / 2;
        if(A[mid-1] < A[mid] && A[mid] > A[mid+1]) return mid;
        if(A[mid-1] < A[mid] && A[mid] < A[mid+1]) left = mid + 1;
        if(A[mid-1] > A[mid] && A[mid] > A[mid+1]) right = mid - 1;
    }
    return left;
}