//
// Created by 李研 on 2019/5/18.
//

#include "MyLeetCode.h"

/*
 * 26. Remove Duplicates from Sorted Array
 * https://leetcode.com/problems/remove-duplicates-from-sorted-array/
 *【专题】Array
 */

int MyLeetCode::removeDuplicates(vector<int> &nums) {
    if(nums.empty()) { return 0; }
    int front = 0, behind = 1;
    while(behind != nums.size()){
        if(nums[behind] != nums[front]){
            nums[++front] = nums[behind];
        }
        behind++;
    }
    return front + 1;
}
