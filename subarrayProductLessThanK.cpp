//
// Created by 李研 on 2019/5/29.
//

/*
 * 713. Subarray Product Less Than K
 * https://leetcode.com/problems/subarray-product-less-than-k/
 */

#include "MyLeetCode.h"

// 尺取法
int MyLeetCode::numSubarrayProductLessThanK(vector<int> &nums, int k) {
    int l = 0, r = 0;
    int product = 1, res = 0;
    while(l < nums.size()){
        while(r < nums.size() && product * nums[r] < k){
            product *= nums[r++];
        }
        res += (r - l);
        product /= nums[l++];
        if(l > r){  // r未移动
            r = l;
            product = 1;
        }
    }
    return res;
}
