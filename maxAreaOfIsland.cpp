//
// Created by 李研 on 2020/2/10.
//

#include "MyLeetCode.h"

/*
 * 695. Max Area of Island
 * https://leetcode.com/problems/max-area-of-island/
 * [专题] 递归
 *
 * 思路与 1036.Escape a Large Maze 相似，
 * 但1036迷宫太大，不适合用二维数组visited[]保存访问状态，
 * 所以使用set及其泛型算法find()，判断当前节点是否被访问。
 */

static vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

static int dfs(const vector<int> &curr, const vector<vector<int>> &grid, vector<vector<bool>> &visited) {
    visited[curr[0]][curr[1]] = true;
    int area = 1;
    for (auto d : dirs) {
        int x = curr[0] + d[0], y = curr[1] + d[1];
        vector<int> next_step = {x, y};
        if (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() // 未越界
            && !visited[x][y]     // 未访问
            && grid[x][y] == 1) { // 是陆地
            area += dfs(next_step, grid, visited);
        }
    }
    return area;
}

int MyLeetCode::maxAreaOfIsland(vector<vector<int>> &grid) {
    vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
    int max_area = 0;
    for (int row = 0; row < grid.size(); ++row) {
        for (int col = 0; col < grid[0].size(); ++col) {
            if (grid[row][col] == 1 && !visited[row][col]) {
                max_area = max(max_area, dfs({row, col}, grid, visited));
            }
        }
    }
    return max_area;
}

