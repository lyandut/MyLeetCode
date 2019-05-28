//
// Created by liyan on 2019-05-28.
//

/*
 * 775. Global and Local Inversions
 * https://leetcode.com/problems/global-and-local-inversions/
 */

#include "MyLeetCode.h"

/*
 * 解法一:
 * 维护前 i 个元素的最大值，每次和 A[i+2] 比较，如果大于 A[i+2]，说明这是个非局部倒置的全局倒置。
 * Runtime: 64 ms, faster than 84.92% submissions.
 */
bool MyLeetCode::isIdealPermutation(vector<int> &A) {
    if(A.size()<3) { return  true; }
    int mx = INT_MIN; // 前i个元素的最大值
    for(int i=0; i<A.size()-2; ++i){
        mx = max(A[i], mx);
        if(A[i+2] < mx) { return false; }
    }
    return true;
}

/*
 * 解法二:
 * 如果乱序数组中某个数字和其坐标差的绝对值大于1，则一定存在非局部倒置的全局倒置。
 * Runtime: 60 ms, faster than 91.80% submissions.
 */
bool isIdealPermutation(vector<int> &A) {
    for(int i=0; i<A.size(); ++i){
        if(abs(A[i] - i) > 1) { return false; }
    }
    return true;
}