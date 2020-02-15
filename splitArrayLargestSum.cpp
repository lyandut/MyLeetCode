//
// Created by 李研 on 2020/2/15.
//

#include "MyLeetCode.h"

/*
 * 410. Split Array Largest Sum
 * https://leetcode.com/problems/split-array-largest-sum/
 */

// 动态规划
//int MyLeetCode::splitArray(vector<int> &nums, int m) {
//    vector<long> prefix_sum(nums.size());
//    prefix_sum[0] = nums[0];
//    transform(nums.begin() + 1, nums.end(), prefix_sum.begin(), prefix_sum.begin() + 1, plus<>());
//
//    // dp[i][j]：将nums[0]~nums[j]划分成i个组中最大和的最小值
//    vector<vector<long>> dp(m + 1, vector<long>(nums.size(), LONG_MAX));
//
//    // 初始化：只划分成一组，即前缀和
//    dp[1].assign(prefix_sum.begin(), prefix_sum.end());
//
//    // 动态规划方程： dp[i][j] = min(dp[i][j], max(dp[i-1][k], prefix_sum[j]-prefix_sum[k]))
//    for (int i = 2; i <= m; ++i)
//        for (int j = i - 1; j < nums.size(); ++j) // 划分成i个组，至少需要nums[0]~nums[i-1]共i个数
//            for (int k = 0; k < j; ++k)
//                dp[i][j] = min(dp[i][j], max(dp[i - 1][k], prefix_sum[j] - prefix_sum[k]));
//
//    return dp[m][nums.size() - 1];
//}


// 二分查找
// 贪心求分组数
static int split(vector<int> &nums, int upper_bound) {
    int pieces_num = 1;
    long piece_sum = 0;
    for (auto num:nums) {
        piece_sum += num;
        if (piece_sum > upper_bound) {
            piece_sum = num;
            ++pieces_num;
        }
    }
    return pieces_num;
}

int MyLeetCode::splitArray(vector<int> &nums, int m) {
    int _max = 0;
    long _sum = 0;
    for (auto num : nums) {
        _max = max(_max, num);
        _sum += num;
    }

    int lo = _max;  // 最小：每个 num 单独一组
    long hi = _sum; // 最大：所有 num 为一组
    while (lo <= hi) {
        int mid = lo + ((hi - lo) >> 1);
        int pieces = split(nums, mid); // 将nums划分为pieces个组，每组的和不超过mid
        if (pieces > m) // 划分组数过多：上界太紧，应放大
            lo = mid + 1;
        else // 划分组数不足或“刚好可以划分”：上界宽松，应尝试缩小
            hi = mid - 1;
    }
    return lo;
}