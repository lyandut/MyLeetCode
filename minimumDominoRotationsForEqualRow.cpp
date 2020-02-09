//
// Created by 李研 on 2020/2/9.
//

#include "MyLeetCode.h"

/*
 * 1007. Minimum Domino Rotations For Equal Row
 * https://leetcode.com/problems/minimum-domino-rotations-for-equal-row/
 *【专题】Array；Greedy
 */

int MyLeetCode::minDominoRotations(vector<int> &A, vector<int> &B) {
    int length = A.size();
    int sameA = A[0], sameB = B[0];
    int i, resA = 0, resB = 0;
    for (i = 0; i < length; i++) {
        if (!(A[i] == sameA || B[i] == sameA)) break;
        if (A[i] != sameA) resA++;
        if (B[i] != sameA) resB++;
        if (i == length - 1) return resA > resB ? resB : resA;
    }
    resA = 0, resB = 0;
    for (i = 0; i < length; i++) {
        if (A[i] != sameB && B[i] != sameB) break;
        if (A[i] != sameB) resA++;
        if (B[i] != sameB) resB++;
        if (i == length - 1) return resA > resB ? resB : resA;
    }

    return -1;
}