//
// Created by 李研 on 2019/7/27.
//

#include "MyLeetCode.h"

/*
 * 1. Two Sum
 * https://leetcode-cn.com/problems/two-sum/
 *【专题】Array；Hash Table
 */

vector<int> MyLeetCode::twoSum(vector<int> &nums, int target) {
    vector<int> res;
    map<int, int> hashMap;
    for(int i=0; i<nums.size(); ++i) {
        int y = target - nums[i];
        auto iter = hashMap.find(y);
        if(iter != hashMap.end()) {
            res = {hashMap[y], i};
            break;
        }
        hashMap[nums[i]] = i;
    }
    return res;
}
