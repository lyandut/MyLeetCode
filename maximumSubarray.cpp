//
// Created by 李研 on 2020/1/11.
//

/*
 * 53. Maximum Subarray
 * https://leetcode.com/problems/maximum-subarray/
 *【专题】Array；Divide and Conquer；Dynamic Programming
 */

#include "MyLeetCode.h"

// 借助原数组就地动态规划
//int MyLeetCode::maxSubArray(vector<int> &nums) {
//    int res = nums[0];
//    for (int i = 1; i < nums.size(); ++i) {
//        nums[i] = max(nums[i], nums[i - 1] + nums[i]);
//        res = max(res, nums[i]);
//    }
//    return res;
//}

// 与上面是同一个方法，思路略有差异
int MyLeetCode::maxSubArray(vector<int> &nums) {
    int res = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
        if (nums[i - 1] > 0) {
            nums[i] = nums[i - 1] + nums[i];
        }
        res = res < nums[i] ? nums[i] : res;
    }
    return res;
}
