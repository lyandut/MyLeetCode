//
// Created by 李研 on 2020/2/10.
//

#include "MyLeetCode.h"

/*
 * 689. Maximum Sum of 3 Non-Overlapping Subarrays
 * https://leetcode.com/problems/maximum-sum-of-3-non-overlapping-subarrays/
 *【专题】Array；Dynamic Programming
 */

vector<int> MyLeetCode::maxSumOfThreeSubarrays(vector<int> &nums, int k) {
    int length = nums.size();
    vector<int> sum(length, nums[0]);
    for (int i = 1; i < length; i++) {
        sum[i] = sum[i - 1] + nums[i];
    }
    int firstMaxIndex = length - 2 * k - 1;
    int thirdMinIndex = 2 * k;
    int secondMinIndex = k;
    int secondMaxIndex = length - k - 1;
    vector<pair<int, int>> firstDp(firstMaxIndex + 1, make_pair(0, 0));
    vector<pair<int, int>> thirdDp(length, make_pair(length - k, 0));
    int newSum;
    for (int i = 0; i <= firstMaxIndex; i++) {
        if (i < secondMinIndex) {
            newSum = sum[k - 1];
            firstDp[i].first = 0;
            firstDp[i].second = newSum;
        } else {
            newSum = sum[i] - sum[i - k];
            if (newSum > firstDp[i - 1].second) {
                firstDp[i].first = i - k + 1;
                firstDp[i].second = newSum;
            } else {
                firstDp[i] = firstDp[i - 1];
            }
        }
    }
    for (int i = length - 1; i >= thirdMinIndex; i--) {
        if (i > secondMaxIndex) {
            newSum = sum[length - 1] - sum[length - 1 - k];
            thirdDp[i].first = length - k;
            thirdDp[i].second = newSum;
        } else {
            newSum = sum[i + k - 1] - sum[i - 1];
            if (newSum >= thirdDp[i + 1].second) {
                thirdDp[i].first = i;
                thirdDp[i].second = newSum;
            } else {
                thirdDp[i] = thirdDp[i + 1];
            }
        }
    }
    int total = 0;
    vector<int> res;
    for (int i = secondMinIndex; i <= secondMaxIndex - k + 1; i++) {
        newSum = sum[i + k - 1] - sum[i - 1];
        if (newSum + firstDp[i - 1].second + thirdDp[i + k].second > total) {
            total = newSum + firstDp[i - 1].second + thirdDp[i + k].second;
            res = {firstDp[i - 1].first, i, thirdDp[i + k].first};
        }
    }
    return res;
}