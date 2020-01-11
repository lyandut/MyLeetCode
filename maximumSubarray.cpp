//
// Created by 李研 on 2020/1/11.
//

/*
 * 53. Maximum Subarray
 * https://leetcode.com/problems/maximum-subarray/
 *【专题】Array；Divide and Conquer；Dynamic Programming
 */

#include "MyLeetCode.h"

int MyLeetCode::maxSubArray(vector<int> &nums) {
    vector<int> dp(nums.size()+1, INT_MIN);
    for(int i=0; i<nums.size(); i++){
        if(dp[i] < 0){
            dp[i+1] = nums[i];
        }
        else{
            dp[i+1] = dp[i]+nums[i];
        }
    }
    return *max_element(dp.begin(), dp.end());
}