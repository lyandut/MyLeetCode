//
// Created by 李研 on 2020/2/9.
//

#include "MyLeetCode.h"

/*
 * LCP 3. 机器人大冒险
 * https://leetcode-cn.com/problems/programmable-robot/
 */

static string to_track(int x, int y, const int xx, const int yy) {
    int k = min(x / xx, y / yy);
    x -= k * xx;
    y -= k * yy;
    return to_string(x) + "," + to_string(y);
}

bool MyLeetCode::robot(string command, vector<vector<int>> &obstacles, int x, int y) {
    unordered_set<string> track;
    track.insert("0,0");
    int xx = 0, yy = 0;
    for (char ch : command) {
        if (ch == 'R') ++xx;
        if (ch == 'U') ++yy;
        track.insert(to_string(xx) + "," + to_string(yy));
    }

    if (track.count(to_track(x, y, xx, yy)) == 0) return false;

    for (auto &obs : obstacles) {
        if (obs[0] > x || obs[1] > y) continue;
        if (track.count(to_track(obs[0], obs[1], xx, yy))) return false;
    }
    return true;
}
