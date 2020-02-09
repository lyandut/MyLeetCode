//
// Created by 李研 on 2020/2/9.
//

#include "MyLeetCode.h"

/*
 * 40. Combination Sum II
 * https://leetcode.com/problems/combination-sum-ii/
 *【专题】Array；Back Tracking
 */

static void _combinationSum2(vector<int> &candidates, int target, vector<vector<int>> &Res, vector<int> &Sum, int index) {
    if (target == 0) {
        Res.push_back(Sum);
        return;
    }
    if (target < 0) return;
    for (int i = index; i < candidates.size(); i++) {
        if (i > index && candidates[i] == candidates[i - 1]) { continue; }
        Sum.push_back(candidates[i]);
        _combinationSum2(candidates, target - candidates[i], Res, Sum, i + 1);
        Sum.pop_back();
    }
}

vector<vector<int>> MyLeetCode::combinationSum2(vector<int> &candidates, int target) {
    vector<vector<int>> Res;
    vector<int> Sum;
    sort(candidates.begin(), candidates.end());
    _combinationSum2(candidates, target, Res, Sum, 0);
    return Res;
}

