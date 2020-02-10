//
// Created by 李研 on 2020/2/10.
//

#include "MyLeetCode.h"

/*
 * 674. Longest Continuous Increasing Subsequence
 * https://leetcode.com/problems/longest-continuous-increasing-subsequence/
 *【专题】Array
 */

int MyLeetCode::findLengthOfLCIS(vector<int> &nums) {
    if (nums.empty()) { return 0; }
    int head = -1;
    int maxSize = 0;
    for (int i = 0; i < nums.size(); i++) {
        if ((i < nums.size() - 1 && nums[i] >= nums[i + 1]) || i == nums.size() - 1) {
            maxSize = max(maxSize, i - head);
            head = i;
        }
    }
    return maxSize;
}