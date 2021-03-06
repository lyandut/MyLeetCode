//
// Created by 李研 on 2020/2/13.
//

#ifndef MYLEETCODE_RANGESUMQUERYMUTABLE_HPP
#define MYLEETCODE_RANGESUMQUERYMUTABLE_HPP

/*
 * 307. Range Sum Query - Mutable
 * https://leetcode.com/problems/range-sum-query-mutable/
 * [线段树 | 树状数组]
 */

#include "DataStructureAndAlgorithm.h"

/*
 * 解法一：线段树
 */
namespace leetcode307_1 {

class NumArray {
private:
    vector<int> seg_tree;
    int _size;

public:
    NumArray(vector<int> &nums) : _size(nums.size()) {
        seg_tree.resize(_size * 2);
        copy(nums.begin(), nums.end(), seg_tree.begin() + _size);
        for (int i = _size - 1; i > 0; --i) {
            seg_tree[i] = seg_tree[2 * i] + seg_tree[2 * i + 1];
        }
    }

    void update(int i, int val) {
        int index = _size + i;
        seg_tree[index] = val;
        int left, right;
        while (index > 0) {
            left = index % 2 ? index - 1 : index;
            right = index % 2 ? index : index + 1;
            seg_tree[index /= 2] = seg_tree[left] + seg_tree[right];
        }
    }

    int sumRange(int i, int j) {
        int iIndex = i + _size, jIndex = j + _size;
        int sum = 0;
        while (iIndex <= jIndex) {
            if (iIndex % 2 != 0) {
                sum += seg_tree[iIndex];
                ++iIndex;
            }
            if (jIndex % 2 != 1) {
                sum += seg_tree[jIndex];
                --jIndex;
            }
            iIndex /= 2;
            jIndex /= 2;
        }
        return sum;
    }
};

}

/*
 * 解法二：树状数组
 */
namespace leetcode307_2 {

class NumArray {
private:
    vector<int> _nums;
    FenwickTree _tree;

public:
    NumArray(vector<int> &nums) : _nums(move(nums)), _tree(_nums) {}

    void update(int i, int val) {
        _tree.update(i + 1, val - _nums[i]);
        _nums[i] = val;
    }

    int sumRange(int i, int j) {
        return _tree.query(j + 1) - _tree.query(i);
    }
};

}

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */

#endif //MYLEETCODE_RANGESUMQUERYMUTABLE_HPP
