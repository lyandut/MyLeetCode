//
// Created by 李研 on 2020/2/9.
//

#include "MyLeetCode.h"

/*
 * 873. Length of Longest Fibonacci Subsequence
 * https://leetcode.com/problems/length-of-longest-fibonacci-subsequence/
 *【专题】Array；Dynamic Programming
 */

/*
 * 解法1. 暴力搜索，26/33个通过测试用例
 */
//int MyLeetCode::lenLongestFibSubseq(vector<int> &A) {
//    int result = 0;
//    for (int i = 0; i < A.size() - 2; i++) {
//        for (int j = i + 1; j < A.size() - 1; j++) {
//            int length = 2;
//            auto iIter = A.begin() + i;
//            auto jIter = A.begin() + j;
//            auto fibIter = find(jIter + 1, A.end(), *iIter + *jIter);
//            while (fibIter != A.end()) {
//                length++;
//                iIter = jIter;
//                jIter = fibIter;
//                fibIter = find(jIter + 1, A.end(), *iIter + *jIter);
//            }
//            result = result > length ? result : length;
//        }
//    }
//    return result > 2 ? result : 0;
//}

/*
 * 解法2. 动态规划
 * A[i] = A[j] + A[k]
 * dp[i][j] = dp[j][k] + 1
 */
int MyLeetCode::lenLongestFibSubseq(vector<int> &A) {
    map<int, int> valueIndex;
    for (int i = 0; i < A.size(); i++) {
        valueIndex[A[i]] = i;
    }
    int result = 0;
    vector<vector<int>> dp(A.size(), vector<int>(A.size(), 2));
    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < i; j++) {
            int Ak = A[i] - A[j];
            if (Ak < A[j] && valueIndex.count(Ak)) {
                int k = valueIndex[Ak];
                dp[i][j] = dp[j][k] + 1;
                result = result > dp[i][j] ? result : dp[i][j];
            }
        }
    }
    return result > 2 ? result : 0;
}