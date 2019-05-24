//
// Created by liyan on 2019-05-24.
//

#include "MyLeetCode.h"
#include <numeric>

/*
 * 643. Maximum Average Subarray I
 * https://leetcode.com/problems/maximum-average-subarray-i/
 */
double MyLeetCode::findMaxAverage(vector<int> &nums, int k) {
    int firIndex = 0;
    int sum = accumulate(nums.begin(), nums.begin()+k, 0);
    int temp = sum;
    for(int i=k; i<nums.size(); ++i){
        temp = temp - nums[firIndex] + nums[i];
        firIndex = i - k + 1;
        sum = max(sum, temp);
    }
    return (double)sum / k;
}
