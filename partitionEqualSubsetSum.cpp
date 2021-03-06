//
// Created by 李研 on 2020/2/15.
//

#include "MyLeetCode.h"

/*
 * 416. Partition Equal Subset Sum
 * https://leetcode.com/problems/partition-equal-subset-sum/
 * [0-1背包、回溯、动态规划]
 */

// 回溯写法
static bool _backtrack(const vector<int> &nums, int index, int target) {
    if (target == 0) return true;
    if (index == nums.size() || target < 0) return false;
    if (_backtrack(nums, index + 1, target - nums[index])) return true;
    int next_index = index + 1;
    while (next_index < nums.size() && nums[next_index] == nums[index]) ++next_index;
    return _backtrack(nums, next_index, target); // 此处回溯
}

// 背包写法
static bool _knapsack(const vector<int> &nums, int index, int target) {
    if (target == 0) return true;
    if (index == nums.size() || target < 0) return false;
    int next_index = index + 1;
    while (next_index < nums.size() && nums[next_index] == nums[index]) ++next_index; // 跳过相同物品
    return _knapsack(nums, index + 1, target - nums[index]) // 放入背包
           || _knapsack(nums, next_index, target); // 不放入背包
}

bool MyLeetCode::canPartition(vector<int> &nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2) return false;
    return _backtrack(nums, 0, sum / 2);
    // return _knapsack(nums, 0, sum / 2);
}

// 动态规划
//bool MyLeetCode::canPartition(vector<int> &nums) {
//    int sum = accumulate(nums.begin(), nums.end(), 0);
//    if (sum % 2) return false;
//    int target = sum / 2;
//    vector<bool> dp(target + 1, false);
//    // 初始化 base case
//    dp[0] = true;
//    // 动态规划填表
//    for (auto num: nums) {
//        for (int i = target; i > 0; --i) { // 正序遍历会导致后趋依赖前趋，不满足“只使用一次”的约束
//            if (i >= num) dp[i] = dp[i] || dp[i - num];
//        }
//    }
//    return dp[target];
//}