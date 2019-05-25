//
// Created by liyan on 2019-05-25.
//

#include "MyLeetCode.h"

/*
 * 154. Find Minimum in Rotated Sorted Array II
 * https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/
 *【专题】Array；Binary Search
 */

int MyLeetCode::findMinII(vector<int> &nums) {
    int mid, left = 0, right = nums.size() - 1;
    while(left < right){
        mid = (left+right) / 2;
        if(nums[mid] > nums[right]) {
            left = mid + 1;
        }
        else if(nums[mid] < nums[right]){
            right = mid;
        }
        else {
            right--;
        }
    }
    return nums[left];
}
