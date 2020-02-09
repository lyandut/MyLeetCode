//
// Created by liyan on 2019-05-27.
//

/*
 * 120. Triangle
 * https://leetcode.com/problems/triangle/
 */

#include "MyLeetCode.h"

/*
 * 递归
 * 42 / 43 test cases passed.
 */
//static int recursion(int i, int j, vector<vector<int>> &triangle) {
//    if (i == triangle.size() - 1) { return triangle[i][j]; }
//    return triangle[i][j] + min(recursion(i + 1, j, triangle), recursion(i + 1, j + 1, triangle));
//}
//
//int MyLeetCode::minimumTotal(vector<vector<int>> &triangle) {
//    return recursion(0, 0, triangle);
//}

/*
 * 回溯
 * 42 / 43 test cases passed.
 */
//static void dfs(int i, int j, int &sum, int &res, vector<vector<int>> &triangle) {
//    sum += triangle[i][j];
//    if (i == triangle.size() - 1) {
//        res = min(res, sum);
//        return;
//    }
//    for (int k = 0; k < 2; ++k) {
//        dfs(i + 1, j + k, sum, res, triangle);
//        sum -= triangle[i + 1][j + k];
//    }
//}
//
//int MyLeetCode::minimumTotal(vector<vector<int>> &triangle) {
//    int res = INT_MAX, sum = 0;
//    dfs(0, 0, sum, res, triangle);
//    return res;
//}

/*
 * DP1
 * 空间复杂度O(n^2)（n为三角形的总行数）
 */
//int MyLeetCode::minimumTotal(vector<vector<int>> &triangle) {
//    vector<vector<int>> dp(triangle.size(), vector<int>(triangle.size()));
//    for (int i = triangle.size() - 1; i >= 0; --i) {
//        for (int j = 0; j < triangle[i].size(); ++j) {
//            if (i == triangle.size() - 1) {
//                dp[i][j] = triangle[i][j];
//            } else {
//                dp[i][j] = triangle[i][j] + min(dp[i + 1][j], dp[i + 1][j + 1]);
//            }
//        }
//    }
//    return dp[0][0];
//}

/*
 * DP2
 * 空间复杂度O(n)（n为三角形的总行数）
 */
//int MyLeetCode::minimumTotal(vector<vector<int>> &triangle) {
//    vector<int> dp(triangle.size() + 1); // 加1不用初始化最后一行
//    for (int i = triangle.size() - 1; i >= 0; --i) {
//        for (int j = 0; j < triangle[i].size(); ++j) {
//            dp[j] = min(dp[j], dp[j + 1]) + triangle[i][j];
//        }
//    }
//    return dp[0];
//}

/*
 * DP3
 * 从倒数第二层开始计算，在原数组基础上修改，空间复杂度为0
 */
int MyLeetCode::minimumTotal(vector<vector<int>> &triangle) {
    for (int i = triangle.size() - 2; i >= 0; --i) {
        for (int j = 0; j < triangle[i].size(); ++j) {
            triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]);
        }
    }
    return triangle[0][0];
}