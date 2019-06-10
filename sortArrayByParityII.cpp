//
// Created by liyan on 2019-06-10.
//

/*
 * 922. Sort Array By Parity II
 * https://leetcode.com/problems/sort-array-by-parity-ii/
 */

#include "MyLeetCode.h"

vector<int> MyLeetCode::sortArrayByParityII(vector<int> &A) {
    int evenIndex = 0, oddIndex = 1;
    int evenLast = A.size() - 1, oddLast = A.size();
    while(true){
        while(evenIndex <= evenLast && A[evenIndex] % 2 == 0) { evenIndex+=2; }
        while(oddIndex <= oddLast && A[oddIndex] % 2) { oddIndex+=2; }
        if(evenIndex <= evenLast && oddIndex <= oddLast) {
            swap(A[oddIndex], A[evenIndex]);
        }
        else{
            return A;
        }
    }
}