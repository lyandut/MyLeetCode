//
// Created by liyan on 2019-06-10.
//

/*
 * 905. Sort Array By Parity
 * https://leetcode.com/problems/sort-array-by-parity/
 */

#include "MyLeetCode.h"

vector<int> MyLeetCode::sortArrayByParity(vector<int> &A) {
    int length = A.size();
    int left = 0, right = length - 1;
    while(1){
        while(left < length && A[left] % 2 == 0) left++;
        while(right > -1 && A[right] % 2) right--;
        if(left < right) {
            swap(A[left], A[right]);
        }
        else {
            return A;
        }
    }
}