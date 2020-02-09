//
// Created by 李研 on 2020/2/9.
//

#include "MyLeetCode.h"

/*
 * LCP 3. 机器人大冒险
 * https://leetcode-cn.com/problems/programmable-robot/
 */

bool MyLeetCode::robot(string command, vector<vector<int>> &obstacles, int x, int y) {
    int ox = 0, oy = 0;
    auto obstaclesX(obstacles);
    auto obstaclesY(obstacles);
    sort(obstaclesX.begin(), obstaclesX.end(),
         [](vector<int> &lhs, vector<int> &rhs) { return lhs[0] > rhs[0]; });
    sort(obstaclesY.begin(), obstaclesY.end(),
         [](vector<int> &lhs, vector<int> &rhs) { return lhs[1] > rhs[1]; });
    while (1) {
        for (auto ch : command) {
            // 移动
            if (ch == 'U') { ++oy; }
            else if (ch == 'R') { ++ox; }
            else { return false; }
            // 边界检测
            if (ox == x && oy == y) { return true; }
            if (ox > x || oy > y) { return false; }
            // 障碍检测
            while (!obstaclesX.empty() && ox >= obstaclesX.back()[0] && oy != obstaclesX.back()[1]) {
                obstaclesX.pop_back();
            }
            if (!obstaclesX.empty() && ox == obstaclesX.back()[0] && oy == obstaclesX.back()[1]) {
                return false;
            }
            while (!obstaclesY.empty() && oy >= obstaclesY.back()[1] && ox != obstaclesY.back()[0]) {
                obstaclesY.pop_back();
            }
            if (!obstaclesY.empty() && ox == obstaclesY.back()[0] && oy == obstaclesY.back()[1]) {
                return false;
            }
        }
    }
}