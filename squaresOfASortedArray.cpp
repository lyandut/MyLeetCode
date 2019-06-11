//
// Created by liyan on 2019-06-11.
//

/*
 * 977. Squares of a Sorted Array
 * https://leetcode.com/problems/squares-of-a-sorted-array/
 */

#include "MyLeetCode.h"

vector<int> MyLeetCode::sortedSquares(vector<int> &A) {
    int left = 0, right = A.size() - 1;
    vector<int> res;
    res.reserve(A.size());
    while(left < right){
        if(abs(A[left]) > abs(A[right])){
            // res.insert(res.begin(), A[left] * A[left]);
            res.push_back(A[left] * A[left]);
            left++;
        }
        else{
            // res.insert(res.begin(), A[right] * A[right]);
            res.push_back(A[right] * A[right]);
            right--;
        }

    }
    // res.insert(res.begin(), A[left] * A[left]);
    res.push_back(A[left] * A[left]);
    reverse(res.begin(), res.end());
    return res;
}