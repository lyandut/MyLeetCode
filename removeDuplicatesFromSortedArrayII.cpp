//
// Created by liyan on 2019-05-25.
//

#include "MyLeetCode.h"

/*
 * 80. Remove Duplicates from Sorted Array II
 * https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/
 *【专题】Array
 */

int MyLeetCode::removeDuplicatesII(vector<int> &nums) {
    if(nums.empty()) { return 0; }
    int front = 0, behind = 1;
    int count = 1;
    while(behind != nums.size()){
        if(nums[behind] != nums[front]){
            nums[++front] = nums[behind];
            count = 1;
        }
        else if(nums[behind] == nums[front] && count < 2){
            count++;
            nums[++front] = nums[behind];
        }
        behind++;
    }
    return front + 1;
}
