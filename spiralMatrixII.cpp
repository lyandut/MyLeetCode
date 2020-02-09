//
// Created by 李研 on 2020/2/9.
//

#include "MyLeetCode.h"

/*
 * 59. Spiral Matrix II
 * https://leetcode.com/problems/spiral-matrix-ii/
 *【专题】Array
 */

vector<vector<int>> MyLeetCode::generateMatrix(int n) {
    vector<vector<int>> Matrix(n, vector<int>(n));
    int iter = 0;
    int val = 1;
    while (val <= n * n) {
        for (int i = iter; i < n - iter; i++)
            Matrix[iter][i] = val++;
        for (int i = iter + 1; i < n - iter; i++)
            Matrix[i][n - 1 - iter] = val++;
        for (int i = n - 2 - iter; i >= iter; i--)
            Matrix[n - 1 - iter][i] = val++;
        for (int i = n - 2 - iter; i > iter; i--)
            Matrix[i][iter] = val++;
        ++iter;
    }
    return Matrix;
}