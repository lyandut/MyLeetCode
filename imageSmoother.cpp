//
// Created by 李研 on 2020/2/9.
//

#include "MyLeetCode.h"

/*
 * 661. Image Smoother
 * https://leetcode.com/problems/image-smoother/
 * [tag] 暴力
 */

vector<vector<int>> MyLeetCode::imageSmoother(vector<vector<int>> &M) {
    int row = M.size();
    int col = M[0].size();
    vector<vector<int>> avgRes(row, vector<int>(col, 0));
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            int sum = M[i][j];
            int count = 1;
            bool up = i - 1 >= 0, down = i + 1 < row, left = j - 1 >= 0, right = j + 1 < col;
            if (up && left) {
                sum += M[i - 1][j - 1];
                count++;
            }
            if (up) {
                sum += M[i - 1][j];
                count++;
            }
            if (up && right) {
                sum += M[i - 1][j + 1];
                count++;
            }
            if (left) {
                sum += M[i][j - 1];
                count++;
            }
            if (right) {
                sum += M[i][j + 1];
                count++;
            }
            if (down && left) {
                sum += M[i + 1][j - 1];
                count++;
            }
            if (down) {
                sum += M[i + 1][j];
                count++;
            }
            if (down && right) {
                sum += M[i + 1][j + 1];
                count++;
            }
            avgRes[i][j] = sum / count;
        }
    }
    return avgRes;
}