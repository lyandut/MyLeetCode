//
// Created by 李研 on 2020/2/10.
//

#include "MyLeetCode.h"

/*
 * 915. Partition Array into Disjoint Intervals
 * https://leetcode.com/problems/partition-array-into-disjoint-intervals/
 *【专题】Array
 */

int MyLeetCode::partitionDisjoint(vector<int> &A) {
    int left = 0, right = A.size() - 1;
    int leftMax = A[left], rightMin = A[right];
    while (left != right - 1) {
        while (A[left + 1] < leftMax) { left++; }
        while (A[right - 1] >= leftMax && right - 1 > left) {
            rightMin = min(A[right - 1], rightMin);
            right--;
        }
        for (int i = left; i < right; i++) {
            leftMax = max(leftMax, A[i]);
        }
        left = right - 1;
        if (leftMax > rightMin) {
            right = A.size() - 1;
            rightMin = A[right];
        }
    }
    return right;
}