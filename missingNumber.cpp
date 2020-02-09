//
// Created by 李研 on 2020/2/9.
//

#include "MyLeetCode.h"

/*
 * 268. Missing Number
 * https://leetcode.com/problems/missing-number/
 * 异或
 */

int MyLeetCode::missingNumber(vector<int> &nums) {
    int n = nums.size();
    for (int i = 0; i < nums.size(); i++) {
        n ^= nums[i];
        n ^= i;
    }
    return n;
}