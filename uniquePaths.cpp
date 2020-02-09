//
// Created by 李研 on 2020/2/9.
//

#include "MyLeetCode.h"

/*
 * 62. Unique Paths
 * https://leetcode.com/problems/unique-paths/
 * 递归、动态规划
 */

int MyLeetCode::uniquePaths(int m, int n) {
    vector<vector<int>> Paths(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == 1 || j == 1)
                Paths[i][j] = 1;
            else {
                Paths[i][j] = Paths[i - 1][j] + Paths[i][j - 1];
            }
        }
    }
    return Paths[m][n];
}