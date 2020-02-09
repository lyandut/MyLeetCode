//
// Created by 李研 on 2020/2/9.
//

#include "MyLeetCode.h"

/*
 * 48. Rotate Image
 * https://leetcode.com/problems/rotate-image/
 * 数学
 */
void MyLeetCode::rotate(vector<vector<int>> &matrix) {
    int n = matrix.size();
    for (int i = 0; i < n / 2; i++) {
        for (int j = i; j < n - 1 - i; j++) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[n - 1 - j][i];                 // 左上 <- 左下
            matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j]; // 左下 <- 右下
            matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i]; // 右下 <- 右上
            matrix[j][n - 1 - i] = temp;                         // 右上 <- 左上
        }
    }
}