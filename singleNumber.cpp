//
// Created by 李研 on 2019/7/28.
//

#include "MyLeetCode.h"

/*
 * 136. Single Number
 * https://leetcode.com/problems/single-number/
 */

int MyLeetCode::singleNumber(vector<int> &nums) {
    int res = 0;
    for(auto num : nums) { res^=num; }
    return res;
}