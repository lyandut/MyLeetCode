//
// Created by 李研 on 2020/2/9.
//

#include "MyLeetCode.h"

/*
 * 1014. Best Sightseeing Pair
 * https://leetcode.com/problems/best-sightseeing-pair/
 *【专题】Array
 */

int MyLeetCode::maxScoreSightseeingPair(vector<int> &A) {
    int valAddIndex = 0, valSubIndex = 0, maxScore = 0;
    for (int i = 0; i < A.size() - 1; i++) {
        valAddIndex = max(valAddIndex, A[i] + i);
        valSubIndex = A[i + 1] - (i + 1);
        maxScore = max(maxScore, valAddIndex + valSubIndex);
    }
    return maxScore;
}