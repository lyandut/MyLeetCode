//
// Created by 李研 on 2020/2/7.
//

#include "MyLeetCode.h"

/*
 * 188. Best Time to Buy and Sell Stock IV
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/
 *【专题】动态规划
 */

/*
 * 动态规划
 * dp[第 i_th 天][最多交易 k_th 次][是否持有股票]
 * dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1]+prices[i])   // 保持 或 卖出
 * dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][0]-prices[i]) // 保持 或 买入
 *
 * 交易流程： dp[k-1][0] ->买入-> dp[k][1] ->卖出-> dp[k][0] ->买入-> dp[k+1][1]
 * 完成一次交易至少需要2天，当最大交易次数 > 天数/2 时，可以认为是允许任意交易，即交易次数无限大
 */

int maxProfitIV_v1(int m, vector<int> &prices) {
    int n = prices.size(); // 天数
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m + 1, vector<int>(2, -1)));
    // 初始化 base case
    for (int k = 1; k <= m; ++k) {
        dp[0][k][0] = 0;          // 第一天没买
        dp[0][k][1] = -prices[0]; // 第一天买入
    }
    for (int i = 0; i < n; ++i) {
        dp[i][0][0] = 0; // 最大交易次数为0
        // dp[i][0][1] 不可能出现这种情况：最大交易次数为0却持有股票
    }
    // 动态规划
    for (int i = 1; i < n; ++i) {
        for (int k = 1; k <= m; ++k) {
            dp[i][k][0] = max(dp[i - 1][k][0], dp[i - 1][k][1] + prices[i]);     // 保持 或 卖出
            dp[i][k][1] = max(dp[i - 1][k][1], dp[i - 1][k - 1][0] - prices[i]); // 保持 或 买入
        }
    }
    return dp[n - 1][m][0];
}

/*
 * 解法 maxProfitIV_v2 比 maxProfitIV_v1 效率略高，但不完善
 * 因为没有处理 k=0 的 base case，即最大交易次数为0的情况
 * 对于算例 m=0, prices={1,3} 能通过, 其实是 vector<int> 初始化时默认值为0
 * 如果指定初值为-1，vector<vector<vector<int>>> dp(n, vector<vector<int>>(m + 1, vector<int>(2, -1))); 则不能通过
 */
int maxProfitIV_v2(int m, vector<int> &prices) {
    int n = prices.size(); // 天数
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m + 1, vector<int>(2)));
    // 初始化 base case
    for (int k = 1; k <= m; ++k) {
        dp[0][k][0] = 0;          // 第一天没买
        dp[0][k][1] = -prices[0]; // 第一天买入
    }
    // 动态规划
    for (int i = 1; i < n; ++i) {
        for (int k = 1; k <= m; ++k) {
            if (k == 1) {
                dp[i][k][0] = max(dp[i - 1][k][0], dp[i - 1][k][1] + prices[i]); // 保持 或 卖出
                dp[i][k][1] = max(dp[i - 1][k][1], -prices[i]);                  // 第一次买入
                continue;
            }
            dp[i][k][0] = max(dp[i - 1][k][0], dp[i - 1][k][1] + prices[i]);     // 保持 或 卖出
            dp[i][k][1] = max(dp[i - 1][k][1], dp[i - 1][k - 1][0] - prices[i]); // 第 k 次买入
        }
    }
    return dp[n - 1][m][0];
}

int MyLeetCode::maxProfitIV(int m, vector<int> &prices) {
    if (prices.empty()) return 0;

    if (m > prices.size() / 2) { // 交易次数无限大，贪心算法
        return MyLeetCode::maxProfitII(prices);
    }

    return maxProfitIV_v1(m, prices);
    // return maxProfitIV_v2(m, prices);
}
