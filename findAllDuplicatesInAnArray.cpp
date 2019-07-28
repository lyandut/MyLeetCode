//
// Created by 李研 on 2019/7/28.
//

#include "MyLeetCode.h"

/*
 * 442. Find All Duplicates in an Array
 * https://leetcode.com/problems/find-all-duplicates-in-an-array/
 */

vector<int> MyLeetCode::findDuplicates(vector<int>& nums) {
    vector<int> res;
    for(int i=0; i<nums.size(); ++i) {
        int index = abs(nums[i]) - 1;
        if(nums[index] < 0) { res.push_back(index + 1); }
        else { nums[index] = -nums[index]; }
    }
    return res;
}
