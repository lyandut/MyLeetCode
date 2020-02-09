//
// Created by 李研 on 2020/2/9.
//

#include "MyLeetCode.h"

/*
 * 830. Positions of Large Groups
 * https://leetcode.com/problems/positions-of-large-groups/
 * 双指针
 */

vector<vector<int>> MyLeetCode::largeGroupPositions(string S) {
    vector<vector<int>> res;
    for (int i = 0, j = i + 1; i < S.size() && j < S.size();) {
        if (S[i] == S[j]) {
            j++;
        }
        if (S[i] != S[j]) {
            if (j - i > 2) {
                vector<int> group = {i, j - 1};
                res.push_back(group);
            }
            i = j;
            j += 1;
        }
    }
    return res;
}