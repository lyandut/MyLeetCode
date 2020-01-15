//
// Created by 李研 on 2020/1/14.
//

/*
 * 312. Burst Balloons
 * https://leetcode.com/problems/burst-balloons/
 *【专题】动态规划
 */

#include "MyLeetCode.h"

int MyLeetCode::maxCoins(vector<int> &nums) {
    vector<int> coins(nums);
    coins.insert(coins.begin(), 1);
    coins.push_back(1);
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    // 区间DP
    for (int r = 2; r < n; ++r) {             // r: 区间长度
        for (int i = 0; i + r < n; ++i) {     // i: 起点
            int j = i + r;                    // j: 终点
            for (int k = i + 1; k < j; ++k) { // k: 遍历区间
                dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j] + coins[i] * coins[k] * coins[j]);
            }
        }
    }
    return dp[0][n - 1];
}