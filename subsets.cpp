//
// Created by 李研 on 2020/2/10.
//

#include "MyLeetCode.h"

/*
 * 78. Subsets
 * https://leetcode.com/problems/subsets/
 *【专题】Array
 */

vector<vector<int>> MyLeetCode::subsets(vector<int> &nums) {
    vector<vector<int>> res;
    res.emplace_back(vector<int>());
    for (int num : nums) {
        auto subSet = res;
        for (auto each : subSet) {
            each.push_back(num);
            res.push_back(each);
        }
    }
    return res;
}