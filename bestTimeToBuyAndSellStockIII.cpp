//
// Created by 李研 on 2020/1/15.
//

/*
 * 123. Best Time to Buy and Sell Stock III
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
 *【专题】动态规划
 */

#include "MyLeetCode.h"

/*
 * 动态规划
 * dp[第 i_th 天][最多交易 k_th 次][是否持有股票]
 * dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1]+prices[i])   // 保持 或 卖出
 * dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][0]-prices[i]) // 保持 或 买入
 *
 * 交易流程： dp[k-1][0] ->买入-> dp[k][1] ->卖出-> dp[k][0] ->买入-> dp[k+1][1]
 */
int MyLeetCode::maxProfitIII(vector<int> &prices) {
    if (prices.empty()) return 0;
    int n = prices.size(); // 天数
    int m = 2;             // 最大交易次数
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m + 1, vector<int>(2)));
    // 初始化 base case
    dp[0][1][0] = 0; // 第一天没买
    dp[0][2][0] = 0;
    dp[0][1][1] = -prices[0]; // 第一天买入
    dp[0][2][1] = -prices[0];
    // 动态规划
    for (int i = 1; i < n; ++i) {
        dp[i][1][0] = max(dp[i - 1][1][0], dp[i - 1][1][1] + prices[i]); // 保持 或 卖出
        dp[i][1][1] = max(dp[i - 1][1][1], -prices[i]);                  // 第一次买入
        dp[i][2][0] = max(dp[i - 1][2][0], dp[i - 1][2][1] + prices[i]); // 保持 或 卖出
        dp[i][2][1] = max(dp[i - 1][2][1], dp[i - 1][1][0] - prices[i]); // 第二次买入
    }
    return dp[n - 1][m][0];
}