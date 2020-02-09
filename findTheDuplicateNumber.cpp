//
// Created by 李研 on 2020/2/9.
//

#include "MyLeetCode.h"

/*
 * 287. Find the Duplicate Number
 * https://leetcode.com/problems/find-the-duplicate-number/
 * [tag] O(1)空间交换
 */
int MyLeetCode::findDuplicate(vector<int> &nums) {
    int temp;
    while (true) {
        if (nums[nums[0]] != nums[0]) {
            temp = nums[0];
            nums[0] = nums[temp];
            nums[temp] = temp;
        } else
            break;
    }
    return nums[0];
}