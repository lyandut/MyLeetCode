//
// Created by 李研 on 2020/2/13.
//

#ifndef MYLEETCODE_RANGESUMQUERYIMMUTABLE_HPP
#define MYLEETCODE_RANGESUMQUERYIMMUTABLE_HPP

/*
 * 303. Range Sum Query - Immutable
 * https://leetcode.com/problems/range-sum-query-immutable/
 * [前缀和]
 */

#include "DataStructureAndAlgorithm.h"

namespace leetcode303 {

class NumArray {
private:
    vector<int> prefix_sum;

public:
    NumArray(vector<int> &nums) {
        prefix_sum.push_back(0);
        for (int num : nums) {
            prefix_sum.push_back(prefix_sum.back() + num);
        }
    }

    int sumRange(int i, int j) {
        return prefix_sum[j + 1] - prefix_sum[i];
    }
};

}
/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */

#endif //MYLEETCODE_RANGESUMQUERYIMMUTABLE_HPP
