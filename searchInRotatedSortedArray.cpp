//
// Created by 李研 on 2019/7/21.
//

#include "MyLeetCode.h"

/*
 * 33. Search in Rotated Sorted Array
 * https://leetcode.com/problems/search-in-rotated-sorted-array/
 */

/*
 * ① 直接二分查找
 */
//int MyLeetCode::search(vector<int> &nums, int target) {
//    int l = 0, r = nums.size() - 1, mid;
//    while(l <= r) {
//        mid = (l + r) / 2;
//        if(nums[mid] == target) { return mid; }
//        if(nums[mid] > nums[l]) { // 左侧有序，右侧乱序
//            if(target >= nums[l] && target < nums[mid]) { // 在左侧
//                r = mid - 1;
//            }
//            else {
//                l = mid + 1;
//            }
//        }
//        else if(nums[mid] < nums[r]) { // 右侧有序，左侧乱序
//            if(target > nums[mid] && target <= nums[r]){ // 在右侧
//                l = mid + 1;
//            }
//            else {
//                r = mid - 1;
//            }
//        }
//        else { // nums[l] >= nums[m] >= nums[r]  <=>  l = m
//            return target == nums[r] ? r : -1;
//        }
//    }
//    return -1;
//}

/*
 * ② 先找到旋转点rotation_index，再进行二分查找
 */
static int binarySearch(vector<int> &nums, int start, int end, int target) {
    int l = start, r = end, mid;
    while (l <= r) {
        mid = (l + r) / 2;
        if (nums[mid] == target) { return mid; }
        if (nums[mid] > target) { r = mid - 1; }
        if (nums[mid] < target) { l = mid + 1; }
    }
    return -1;
}

int MyLeetCode::search(vector<int> &nums, int target) {
    int l = 0, r = nums.size() - 1, mid;
    int rotation_index = 0;
    while (l < r) {
        mid = (l + r) / 2;
        if (nums[mid] > nums[mid+1]) {
            rotation_index = mid + 1;
            break;
        }
        if (nums[mid] > nums[l]) { l = mid; }
        if (nums[mid] < nums[r]) { r = mid; }
    }
    int l_res = binarySearch(nums, 0, rotation_index - 1, target);
    int r_res = binarySearch(nums, rotation_index, nums.size() - 1, target);

    return l_res == -1 ? r_res : l_res;
}
