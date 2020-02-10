//
// Created by 李研 on 2020/2/10.
//

#include "MyLeetCode.h"

/*
 * 560. Subarray Sum Equals K
 * https://leetcode.com/problems/subarray-sum-equals-k/
 *【专题】Array；Hash Table
 */

int MyLeetCode::subarraySum(vector<int> &nums, int k) {
    map<int, int> sumMap;
    int sum = 0, res = 0;
    sumMap[sum] = 1;
    for (int num : nums) {
        sum += num;
        if (sumMap.find(sum - k) != sumMap.end()) {
            res += sumMap[sum - k];
        }
        sumMap[sum]++;
    }
    return res;
}