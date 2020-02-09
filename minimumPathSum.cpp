//
// Created by 李研 on 2020/2/9.
//

#include "MyLeetCode.h"

/*
 * 64. Minimum Path Sum
 * https://leetcode.com/problems/minimum-path-sum/
 *【专题】Array；Dynamic Programming
 */

static int _minPathSum(vector<vector<int>> &grid, int m, int n) {
    vector<vector<int>> Paths(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 && j == 0)
                Paths[i][j] = grid[i][j];
            else if (i == 0 && j > 0)
                Paths[i][j] = Paths[i][j - 1] + grid[i][j];
            else if (i > 0 && j == 0)
                Paths[i][j] = Paths[i - 1][j] + grid[i][j];
            else
                Paths[i][j] = min(Paths[i - 1][j], Paths[i][j - 1]) + grid[i][j];
        }
    }
    return Paths[m - 1][n - 1];
}

int MyLeetCode::minPathSum(vector<vector<int>> &grid) {
    int m = grid.size();
    int n = grid[0].size();
    return _minPathSum(grid, m, n);
}

