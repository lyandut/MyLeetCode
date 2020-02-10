//
// Created by 李研 on 2020/2/10.
//

#include "MyLeetCode.h"

/*
 * 945. Minimum Increment to Make Array Unique
 * https://leetcode.com/problems/minimum-increment-to-make-array-unique/
 *【专题】Array
 */

int MyLeetCode::minIncrementForUnique(vector<int> &A) {
    int res = 0;
    vector<int> vec(40001, 0);
    vector<int> dupVec;
    for (int each : A) {
        vec[each]++;
        if (vec[each] > 1) { dupVec.push_back(each); }
    }
    if (dupVec.empty()) { return 0; }
    sort(dupVec.begin(), dupVec.end());
    auto iter = dupVec.begin();
    for (int i = (*iter) + 1; iter != dupVec.end(); i++) {
        if (vec[i] == 0 && i > (*iter)) {
            res += i - (*iter);
            vec[i]++;
            iter++;
        }
    }
    return res;
}