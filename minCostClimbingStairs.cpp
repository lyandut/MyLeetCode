//
// Created by 李研 on 2020/2/9.
//

#include "MyLeetCode.h"

/*
 * 746. Min Cost Climbing Stairs
 * https://leetcode.com/problems/min-cost-climbing-stairs/
 *【专题】Array；Dynamic Programming
 */

static int _minCostClimbingStairs_v1(vector<int> &cost, int n) {
    if (n == 0 || n == 1) { return cost[n]; }
    return min(_minCostClimbingStairs_v1(cost, n - 1), _minCostClimbingStairs_v1(cost, n - 2)) + cost[n];
}

static int _minCostClimbingStairs_v2(vector<int> &cost, int n) {
    vector<int> Costs(n, 0);
    for (int i = 0; i < n; i++) {
        if (i == 0 || i == 1)
            Costs[i] = cost[i];
        else
            Costs[i] = min(Costs[i - 1], Costs[i - 2]) + cost[i];
    }
    return Costs[n - 1];
}

int MyLeetCode::minCostClimbingStairs(vector<int> &cost) {
    cost.push_back(0);
    return _minCostClimbingStairs_v2(cost, cost.size());
}