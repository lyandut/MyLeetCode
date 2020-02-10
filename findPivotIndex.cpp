//
// Created by 李研 on 2020/2/10.
//

#include "MyLeetCode.h"

/*
 * 724. Find Pivot Index
 * https://leetcode.com/problems/find-pivot-index/
 *【专题】Array
 */

int MyLeetCode::pivotIndex(vector<int> &nums) {
    vector<int> sums;
    sums.push_back(0);
    for (int i = 0; i < nums.size(); i++) {
        sums.push_back(sums[i] + nums[i]);
    }
    for (int j = 0; j < nums.size(); j++) {
        if (sums[j] == sums[sums.size() - 1] - sums[j + 1])
            return j;
    }
    return -1;
}