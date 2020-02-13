//
// Created by 李研 on 2020/2/13.
//

#include "MyLeetCode.h"

/*
 * 56. Merge Intervals
 * https://leetcode.com/problems/merge-intervals/
 * [区间操作]
 */

vector<vector<int>> MyLeetCode::merge(vector<vector<int>> &intervals) {
    vector<vector<int>> res;
    if (intervals.empty()) return res;
    sort(intervals.begin(), intervals.end(),
         [](const vector<int> &lhs, const vector<int> &rhs) {
             return lhs[0] < rhs[0];
         }
    );
    for (const auto &interval : intervals) {
        if (res.empty() || res.back()[1] < interval[0]) {
            res.emplace_back(interval);
        } else {
            res.back()[1] = max(res.back()[1], interval[1]);
        }
    }
    return res;
}