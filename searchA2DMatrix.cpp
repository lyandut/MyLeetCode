//
// Created by 李研 on 2019/7/25.
//

#include "MyLeetCode.h"

/*
 * 74. Search a 2D Matrix
 * https://leetcode.com/problems/search-a-2d-matrix/
 */

bool MyLeetCode::searchMatrix(vector<vector<int>> &matrix, int target) {
    int m = matrix.size();
    if(m == 0) { return false; }
    int n = matrix[0].size();
    int l = 0, r = m * n - 1, mid;
    while (l <= r) {
        mid = (l + r) / 2;
        int tmp = matrix[mid / n][mid % n];
        if(tmp == target) { return true; }
        else if(tmp < target) { l = mid + 1; }
        else { r = mid - 1; }
    }
    return false;
}
