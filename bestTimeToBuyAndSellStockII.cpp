//
// Created by 李研 on 2020/1/15.
//

/*
 * 122. Best Time to Buy and Sell Stock II
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
 */

#include "MyLeetCode.h"

/*
 * 1. 贪心算法，时空复杂度均优于动态规划
 */
//int MyLeetCode::maxProfitII(vector<int> &prices) {
//    int maxPro = 0;
//    for (int i = 1; i < prices.size(); ++i) {
//        if (prices[i] - prices[i - 1] > 0) {
//            maxPro += prices[i] - prices[i - 1];
//        }
//    }
//    return maxPro;
//}

/*
 * 2. 动态规划
 * dp[第 i_th 天][是否持有股票]
 * dp[i][0] = max(dp[i-1][0], dp[i-1][1]+prices[i]) // 保持 或 卖出
 * dp[i][1] = max(dp[i-1][1], dp[i-1][0]-prices[i]) // 保持 或 买入
 */
int MyLeetCode::maxProfitII(vector<int> &prices) {
    if (prices.empty()) return 0;
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(2));
    // 初始化
    dp[0][0] = 0;          // 第一天没买
    dp[0][1] = -prices[0]; // 第一天买入
    // 动态规划填表
    for (int i = 1; i < n; ++i) {
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
        dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
    }
    return dp[n - 1][0];
}