//
// Created by liyan on 2021/5/31.
//

#include "MyLeetCode.h"

/*
 * LCP 08. 剧情触发时间
 * https://leetcode-cn.com/problems/ju-qing-hong-fa-shi-jian/
 */

static int binary_search(vector<vector<int>> &resource, int rid, int target) {
    int l = 0, r = resource.size() - 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (resource[mid][rid] < target)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return l == resource.size() ? -1 : l;
}

vector<int> MyLeetCode::getTriggerTime(vector<vector<int>> &increase, vector<vector<int>> &requirements) {
    vector<vector<int>> resource(1, vector<int>(3, 0));
    for (auto &each : increase) {
        auto &before = resource.back();
        resource.push_back({before[0] + each[0], before[1] + each[1], before[2] + each[2]});
    }

    vector<int> res;
    for (auto &each : requirements) {
        int r = -1;
        for (int i = 0; i < 3; ++i) {
            int ri = binary_search(resource, i, each[i]);
            if (ri == -1) {
                r = -1;
                break;
            }
            r = max(r, ri);
        }
        if (r == -1) res.push_back(-1);
        else res.push_back(r);
    }
    return res;
}