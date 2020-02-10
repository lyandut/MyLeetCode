//
// Created by 李研 on 2020/2/10.
//

#include "MyLeetCode.h"

/*
 * 90. Subsets II
 * https://leetcode.com/problems/subsets-ii/
 *【专题】Array
 */

vector<vector<int>> MyLeetCode::subsetsWithDup(vector<int> &nums) {
    vector<vector<int>> res;
    res.emplace_back(vector<int>());
    sort(nums.begin(), nums.end());
    int dupCount = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (i != 0 && nums[i] == nums[i - 1]) {
            dupCount++;
            auto subSet = res;
            for (auto each : subSet) {
                if (count(each.begin(), each.end(), nums[i]) == dupCount) {
                    each.push_back(nums[i]);
                    res.push_back(each);
                }
            }
        } else {
            dupCount = 0;
            auto subSet = res;
            for (auto each : subSet) {
                each.push_back(nums[i]);
                res.push_back(each);
            }
        }

    }
    return res;
}