//
// Created by 李研 on 2020/2/10.
//

#include "MyLeetCode.h"

/*
 * 66. Plus One
 * https://leetcode.com/problems/plus-one/
 *【专题】Array
 */

vector<int> MyLeetCode::plusOne(vector<int> &digits) {
    int c = 1;
    for (int i = digits.size() - 1; i >= 0; i--) {
        int sum = digits[i] + c;
        digits[i] = sum % 10;
        c = sum / 10;
    }
    if (c) { digits.insert(digits.begin(), 1); }
    return digits;
}