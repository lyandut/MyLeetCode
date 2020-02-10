//
// Created by 李研 on 2020/2/10.
//

#include "MyLeetCode.h"

/*
 * 128. Longest Consecutive Sequence
 * https://leetcode.com/problems/longest-consecutive-sequence/
 *【专题】Array；Union Find
 */

int MyLeetCode::longestConsecutive(vector<int> &nums) {
    map<int, int> hashMap;
    int left, right, curr, max = 0;
    for (int num : nums) {
        if (hashMap[num]) { continue; }
        left = hashMap[num - 1];
        right = hashMap[num + 1];
        hashMap[num] = curr = left + right + 1;
        hashMap[num - left] = curr;
        hashMap[num + right] = curr;
        max = curr > max ? curr : max;
    }
    return max;
}