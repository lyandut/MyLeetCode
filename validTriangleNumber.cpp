//
// Created by 李研 on 2020/2/10.
//

#include "MyLeetCode.h"

/*
 * 611. Valid Triangle Number
 * https://leetcode.com/problems/valid-triangle-number/
 *【专题】Array
 */

int MyLeetCode::triangleNumber(vector<int> &nums) {
    int count = 0;
    sort(nums.begin(), nums.end());
    for (int i = 2; i < nums.size(); i++) {
        for (int j = 0; j < i - 1; j++) {
            for (int k = j + 1; k < i; k++) {
                if (nums[j] + nums[k] > nums[i]) {
                    count += i - k;
                    break;
                }
            }
        }
    }
    return count;
}