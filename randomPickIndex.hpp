//
// Created by 李研 on 2020/2/13.
//

#ifndef MYLEETCODE_RANDOMPICKINDEX_HPP
#define MYLEETCODE_RANDOMPICKINDEX_HPP

/*
 * 398. Random Pick Index
 * https://leetcode.com/problems/random-pick-index/
 * [水塘抽样]
 */

#include "DataStructureAndAlgorithm.h"

namespace leetcode398 {

class Solution {
private:
    vector<int> _nums;

public:
    Solution(vector<int> &nums) {
        _nums = nums;
    }

    int pick(int target) {
        int res = 0;
        int cnt = 0;
        for (int i = 0; i < _nums.size(); ++i) {
            if (_nums[i] == target) {
                ++cnt;
                if (rand() % cnt == 0) { // 以 1/cnt 的概率选择当前下标
                    res = i;
                }
            }
        }
        return res;
    }
};

}
/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */

#endif //MYLEETCODE_RANDOMPICKINDEX_HPP
