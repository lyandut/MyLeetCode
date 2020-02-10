//
// Created by 李研 on 2020/2/10.
//

#include "MyLeetCode.h"

/*
 * 27. Remove Element
 * https://leetcode.com/problems/remove-element/
 *【专题】Array；Two Pointers
 */

int MyLeetCode::removeElement(vector<int> &nums, int val) {
    int left = 0;
    int right = nums.size() - 1;
    while (left <= right) {
        while (left < nums.size() && nums[left] != val) { left++; }
        while (right >= 0 && nums[right] == val) { right--; }
        if (left < right) {
            int tmp = nums[left];
            nums[left] = nums[right];
            nums[right] = tmp;
        }
    }
    return left;
}