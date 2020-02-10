//
// Created by 李研 on 2020/2/10.
//

#include "MyLeetCode.h"

/*
 * 795. Number of Subarrays with Bounded Maximum
 * https://leetcode.com/problems/number-of-subarrays-with-bounded-maximum/
 *【专题】Array
 */

int MyLeetCode::numSubarrayBoundedMax(vector<int> &A, int L, int R) {
    int count = 0;
    for (int i = 0; i < A.size(); i++) {
        if (A[i] > R) { continue; }
        if (A[i] >= L) { count++; }
        int curMax = A[i];
        for (int j = i + 1; j < A.size(); j++) {
            curMax = max(curMax, A[j]);
            if (curMax > R) { break; }
            if (curMax >= L) { count++; }
        }
    }
    return count;
}