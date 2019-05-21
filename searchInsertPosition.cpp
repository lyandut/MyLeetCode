//
// Created by liyan on 2019-05-19.
//

#include "MyLeetCode.h"

/*
 * 35. Search Insert Position
 * https://leetcode.com/problems/search-insert-position/
 *【专题】Array
 */

int MyLeetCode::searchInsert(vector<int> &nums, int target) {
    int left = 0, right = nums.size() - 1, mid;
    while(left < right){
        mid = (left + right) / 2;
        if(nums[mid] > target){
            right = mid - 1;
        }
        else if(nums[mid] < target){
            left = mid + 1;
        }
        else {
            return mid;
        }
    }
    return nums[left] >= target ? left : left+1;
}
