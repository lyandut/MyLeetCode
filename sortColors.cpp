//
// Created by liyan on 2019/9/23.
//

/*
 * 75. Sort Colors
 * https://leetcode.com/problems/sort-colors/
 *【专题】Array；Two Pointers；Sort
 */

#include "MyLeetCode.h"

void MyLeetCode::sortColors(vector<int> &nums) {
    int left = 0, right = nums.size() - 1;
    int curr = 0;
    while(curr <= right){
        if(nums[curr] == 0 && curr > left){
            swap(nums[curr], nums[left]);
            left++;
        }
        else if(nums[curr] == 2){
            swap(nums[curr], nums[right]);
            right--;
        }
        else{
            curr++;
        }
    }
}