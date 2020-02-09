//
// Created by 李研 on 2020/2/9.
//

#include "MyLeetCode.h"

/*
 * 769. Max Chunks To Make Sorted
 * https://leetcode.com/problems/max-chunks-to-make-sorted/
 */

int MyLeetCode::maxChunksToSorted(vector<int> &arr) {
    int left = 0, right = 0;
    int res = 0;
    while (left < arr.size()) {
        right = arr[left];
        while (left < right) {
            left++;
            right = max(right, arr[left]);
        }
        res++;
        left++;
    }
    return res;
}