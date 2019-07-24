//
// Created by 李研 on 2019/7/24.
//

#include "MyLeetCode.h"

/*
 * 81. Search in Rotated Sorted Array II
 * https://leetcode.com/problems/search-in-rotated-sorted-array-ii/
 */

bool MyLeetCode::searchII(vector<int> &nums, int target) {
    int l = 0, r = nums.size() - 1, mid;
    while (l <= r) {
        mid = (l + r) / 2;
        if(nums[mid] == target) { return true; }
        if(nums[mid] > nums[l]) { // 左侧有序，右侧乱序
            if(nums[l] <= target && target < nums[mid]) { // 在左侧
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        else if(nums[mid] < nums[r]) {  // 右侧有序，左侧乱序
            if(nums[mid] < target && target <= nums[r]) { // 在右侧
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        else { // nums[l] >= nums[m] >= nums[r]
            if(nums[mid] != nums[l]) {
                r = mid - 1;
            }
            else if(nums[mid] != nums[r]) {
                l = mid + 1;
            }
            else {
                int i = mid;
                for(; i>l; --i) {
                    if(nums[i] != nums[l]) { break; }
                }
                if(i == l) {
                    l = mid + 1;
                }
                else {
                    r = i;
                }
            }
        }
    }
    return false;
}