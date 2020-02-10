//
// Created by 李研 on 2020/2/10.
//

#include "MyLeetCode.h"

/*
 * 870. Advantage Shuffle
 * https://leetcode.com/problems/advantage-shuffle/
 *【专题】Array
 */

vector<int> MyLeetCode::advantageCount(vector<int> &A, vector<int> &B) {
    int length = A.size();
    vector<int> res(length);
    multimap<int, int> bIndexMap;
    for (int i = 0; i < length; i++) {
        bIndexMap.insert(make_pair(B[i], i));
    }
    sort(A.begin(), A.end());
    auto r_iter = bIndexMap.rbegin();
    int left = 0, right = length - 1;
    while (left <= right) {
        if ((*r_iter).first >= A[right]) {
            res[(*r_iter).second] = A[left++];
        } else {
            res[(*r_iter).second] = A[right--];
        }
        r_iter++;
    }
    return res;
}