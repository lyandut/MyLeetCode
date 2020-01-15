//
// Created by 李研 on 2020/1/15.
//

/*
 * 122. Best Time to Buy and Sell Stock II
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
 *【专题】贪心算法
 */

#include "MyLeetCode.h"

int MyLeetCode::maxProfitII(vector<int> &prices) {
    int maxPro = 0;
    for (int i = 1; i < prices.size(); ++i) {
        if (prices[i] - prices[i - 1] > 0) {
            maxPro += prices[i] - prices[i - 1];
        }
    }
    return maxPro;
}