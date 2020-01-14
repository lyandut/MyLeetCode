//
// Created by 李研 on 2020/1/14.
//

/*
 * 198. House Robber
 * https://leetcode.com/problems/house-robber/
 *【专题】动态规划
 */

#include "MyLeetCode.h"

int MyLeetCode::rob(vector<int> &nums) {
    if (nums.empty()) return 0;
    if (nums.size() == 1) return nums[0];
    vector<int> states(nums.size());
    states[0] = nums[0];
    states[1] = max(nums[0], nums[1]);
    for (int i = 2; i < states.size(); ++i) {
        states[i] = max(states[i - 1], states[i - 2] + nums[i]);
    }
    return *max_element(states.begin(), states.end());
}
