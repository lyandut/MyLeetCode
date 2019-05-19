//
// Created by liyan on 2019-05-19.
//

#include "MyLeetCode.h"

/*
 * 747. Largest Number At Least Twice of Others
 * https://leetcode.com/problems/largest-number-at-least-twice-of-others/
 */

int MyLeetCode::dominantIndex(vector<int> &nums) {
    if(nums.size() < 2) { return 0; }
    int maxIndex, secIndex;
    if(nums[0] > nums[1]){
        maxIndex = 0;
        secIndex = 1;
    }
    else{
        maxIndex = 1;
        secIndex = 0;
    }
    for(int i=2; i<nums.size(); i++){
        if(nums[i] > nums[maxIndex]){
            secIndex = maxIndex;
            maxIndex = i;
        }
        else if(nums[i] > nums[secIndex]){
            secIndex = i;
        }
    }
    return nums[maxIndex] >= 2*nums[secIndex] ? maxIndex : -1;
}
