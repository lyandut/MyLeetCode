//
// Created by 李研 on 2020/1/27.
//

#include "MyLeetCode.h"

/*
 * 1036. Escape a Large Maze
 * https://leetcode.com/problems/escape-a-large-maze/
 *  BFS/DFS
 */

static vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

// Ps：如果写在内类成为成员函数，必须加 static 成为静态成员函数
static string trans_op(const vector<int> &coord) { return to_string(coord[0]) + "," + to_string(coord[1]); }

static bool dfs(vector<int> &source, vector<int> &target, vector<int> &curr, unordered_set<string> &blocked_set, unordered_set<string> &visited) {
    // curr == target，到达终点
    if (curr[0] == target[0] && curr[1] == target[1])
        return true;
    // |source -> curr| 的曼哈顿距离大于 blocked_set.size() 说明从 source 出发一定能到达 curr 点
    if (abs(source[0] - curr[0]) + abs(source[1] - curr[1]) > blocked_set.size())
        return true;

    // DFS
    visited.insert(trans_op(curr));
    for (auto d : dirs) {
        int x = d[0] + curr[0];
        int y = d[1] + curr[1];
        vector<int> next_step = {x, y};
        if (x >= 0 && x < 1000000 && y >= 0 && y < 1000000                // 未越界
            && blocked_set.find(trans_op(next_step)) == blocked_set.end() // 未封锁
            && visited.find(trans_op(next_step)) == visited.end()) {      // 未访问
            if (dfs(source, target, next_step, blocked_set, visited))
                return true;
        }
    }
    return false;
}

bool MyLeetCode::isEscapePossible(vector<vector<int>> &blocked, vector<int> &source, vector<int> &target) {
    unordered_set<string> blocked_set, visited1, visited2;
    // 使用泛型算法 transform() 代替 for 循环，set 必须使用 inserter 代替赋值运算
    transform(blocked.begin(), blocked.end(), inserter(blocked_set, blocked_set.end()), trans_op);
    return dfs(source, target, source, blocked_set, visited1)     // 起点出发能到达终点 或者 到达某点时已超过一定步数
           && dfs(target, source, target, blocked_set, visited2); // 反之亦能
}
