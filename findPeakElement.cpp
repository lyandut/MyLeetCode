//
// Created by 李研 on 2020/2/10.
//

#include "MyLeetCode.h"

/*
 * 162. Find Peak Element
 * https://leetcode.com/problems/find-peak-element/
 *【专题】Array；Binary Search
 */

int MyLeetCode::findPeakElement(vector<int> &nums) {
    int left = 0, right = nums.size() - 1, mid;
    while (left < right) {
        mid = (left + right) / 2;
        if (nums[mid] < nums[mid + 1])
            left = mid + 1;
        else if (mid > 0 && nums[mid] < nums[mid - 1])
            right = mid - 1;
        else
            return mid;
    }
    return left;
}