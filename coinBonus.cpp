//
// Created by 李研 on 2020/2/9.
//

#include "MyLeetCode.h"

/*
 * LCP 5. 发 LeetCoin
 * https://leetcode-cn.com/problems/coin-bonus/
 */

static void recursiveBonus(vector<int> &coinList, unordered_map<int, vector<int>> &leaderShipMap, int leader, int coins) {
    coinList[leader] += coins;
    if (leaderShipMap.find(leader) == leaderShipMap.end()) { return; }
    for (int subLeader : leaderShipMap[leader]) {
        recursiveBonus(coinList, leaderShipMap, subLeader, coins);
    }
}

static int recursiveSum(vector<int> &coinList, unordered_map<int, vector<int>> &leaderShipMap, int leader) {
    if (leaderShipMap.find(leader) == leaderShipMap.end()) { return coinList[leader]; }
    int sum = coinList[leader];
    for (int subLeader : leaderShipMap[leader]) {
        sum += recursiveSum(coinList, leaderShipMap, subLeader);
    }
    return sum;
}

vector<int> MyLeetCode::bonus(int n, vector<vector<int>> &leadership, vector<vector<int>> &operations) {
    vector<int> res;

    // 建立领导关系
    unordered_map<int, vector<int>> leaderShipMap;
    for (auto &each_pair : leadership) {
        leaderShipMap[each_pair[0]].push_back(each_pair[1]);
    }

    // 执行 operations
    vector<int> coinList(n + 1, 0);
    for (auto &op : operations) {
        if (op[0] == 1) {
            coinList[op[1]] += op[2];
        } else if (op[0] == 2) {
            recursiveBonus(coinList, leaderShipMap, op[1], op[2]);
        } else if (op[0] == 3) {
            res.push_back(recursiveSum(coinList, leaderShipMap, op[1]));
        }
    }

    return res;
}