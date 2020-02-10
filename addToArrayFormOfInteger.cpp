//
// Created by 李研 on 2020/2/10.
//

#include "MyLeetCode.h"

/*
 * 989. Add to Array-Form of Integer
 * https://leetcode.com/problems/add-to-array-form-of-integer/
 *【专题】Array
 */

vector<int> MyLeetCode::addToArrayForm(vector<int> &A, int K) {
    int index = A.size();
    while (index && K) {
        K = A[index - 1] + K;
        A[index - 1] = K % 10;
        K /= 10;
        index--;
    }
    while (K) {
        A.insert(A.begin(), K % 10);
        K /= 10;
    }
    return A;
}