//
// Created by 李研 on 2020/2/10.
//

#include "MyLeetCode.h"

/*
 * 119. Pascal's Triangle II
 * https://leetcode.com/problems/pascals-triangle-ii/
 *【专题】Array
 */

vector<int> MyLeetCode::getRow(int rowIndex) {
    int numRows = rowIndex + 1;
    vector<vector<int>> PascalsTriangle;
    PascalsTriangle.reserve(numRows);

    PascalsTriangle.emplace_back(vector<int>(1, 1));
    int right, left;
    for (int i = 1; i < numRows; i++) {
        vector<int> ithRow;
        for (int j = 0; j <= i; j++) {
            right = i - 1 < j ? 0 : PascalsTriangle[i - 1][j];
            left = j - 1 < 0 ? 0 : PascalsTriangle[i - 1][j - 1];
            ithRow.push_back(right + left);
        }
        PascalsTriangle.push_back(ithRow);
    }
    return PascalsTriangle[rowIndex];
}