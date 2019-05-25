//
// Created by liyan on 2019-05-25.
//

#include "MyLeetCode.h"

/*
 * 153. Find Minimum in Rotated Sorted Array
 * https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
 *【专题】Array；Binary Search
 */

int MyLeetCode::findMin(vector<int> &nums) {
    int mid, left = 0, right = nums.size() - 1;
    while(left < right){
        mid = (left+right) / 2;
        if(nums[mid] > nums[right]) {
            left = mid + 1;
        }
        else {
            right = mid;
        }
    }
    return nums[left];
}
