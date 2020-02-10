//
// Created by 李研 on 2020/2/10.
//

#include "MyLeetCode.h"

/*
 * 1018. Binary Prefix Divisible By 5
 * https://leetcode.com/problems/binary-prefix-divisible-by-5/
 *【专题】Array
 */

vector<bool> MyLeetCode::prefixesDivBy5(vector<int> &A) {
    vector<bool> res;
    res.reserve(A.size());
    int iAnswer = 0;
    for (int a : A) {
        iAnswer = (iAnswer * 2 + a) % 5;
        res.push_back(iAnswer == 0);
    }
    return res;
}