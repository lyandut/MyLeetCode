//
// Created by 李研 on 2019/7/27.
//

#include "MyLeetCode.h"

/*
 * 169. Majority Element
 * https://leetcode.com/problems/majority-element/
 */

int MyLeetCode::majorityElement(vector<int> &nums) {
    int major, count = 0;
    for(auto num : nums) {
        if(count == 0) { major = num; }
        count += (num == major) ? 1 : -1;
    }
    return major;
}