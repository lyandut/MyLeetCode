//
// Created by 李研 on 2020/2/10.
//

#include "MyLeetCode.h"

/*
 * 11. Container With Most Water
 * https://leetcode.com/problems/container-with-most-water/
 *【专题】Array；Two Pointers
 */

int MyLeetCode::maxArea(vector<int> &height) {
    int left = 0, right = height.size() - 1;
    int result = 0;
    while (left < right) {
        int newContain = min(height[left], height[right]) * (right - left);
        if (newContain > result) {
            result = newContain;
        }
        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }
    return result;
}