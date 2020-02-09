//
// Created by 李研 on 2020/2/9.
//

#include "MyLeetCode.h"

/*
 * 39. Combination Sum
 * https://leetcode.com/problems/combination-sum/
 * 递归、回溯
 */

static void _combinationSum(vector<int> &candidates, int target, vector<vector<int>> &Res, vector<int> &Sum, int index) {
    if (target == 0) {
        Res.push_back(Sum);
        return;
    }
    if (target < 0) return;
    for (int i = index; i < candidates.size(); i++) {
        Sum.push_back(candidates[i]);
        _combinationSum(candidates, target - candidates[i], Res, Sum, i);
        Sum.pop_back();
    }
}

vector<vector<int>> MyLeetCode::combinationSum(vector<int> &candidates, int target) {
    vector<vector<int>> Res;
    vector<int> Sum;
    sort(candidates.begin(), candidates.end());
    _combinationSum(candidates, target, Res, Sum, 0);
    return Res;
}