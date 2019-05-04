//
// Created by liyan on 2018-12-31.
//

#ifndef MYLEETCODE_MYLEETCODE_H
#define MYLEETCODE_MYLEETCODE_H

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <tuple>
#include <unordered_map>
using namespace std;

class MyLeetCode {
public:
    // 1. Two Sum
    vector<int> twoSum(vector<int>& nums, int target);
    // 11. 盛最多水的容器
    int maxArea(vector<int>& height);
    // 27. 移除元素
    int removeElement(vector<int>& nums, int val);
    // 39. 组合总和
    vector<vector<int>> combinationSum(vector<int>& candidates, int target);
    void recursive(vector<int> &candidates, int target, vector<vector<int>> &res, vector<int> &curr, int index);
    // 48. 旋转图像
    void rotate(vector<vector<int>>& matrix);
    // 53. 最大子序和
    int maxSubArray(vector<int>& nums);
    // 59. 螺旋矩阵 II
    vector<vector<int>> generateMatrix(int n);
    // 62. 不同路径
    int uniquePaths(int m, int n);
    // 64. 最小路径和
    int minPathSum(vector<vector<int>>& grid);
    int _minPathSum(vector<vector<int>> &grid, int m, int n);
    // 118. 杨辉三角
    vector<vector<int>> generate(int numRows);
    // 119. 杨辉三角 II
    vector<int> getRow(int rowIndex);
    // 121. 买卖股票的最佳时机
    int maxProfit(vector<int>& prices);
    // 153. 寻找旋转排序数组中的最小值
    int findMin(vector<int>& nums);
    // 268. 缺失数字
    int missingNumber(vector<int>& nums);
    // 287. 寻找重复数
    int findDuplicate(vector<int>& nums);
    // 392. 判断子序列
    bool isSubsequence(string s, string t);
    // 540. 有序数组中的单一元素
    int singleNonDuplicate(vector<int>& nums);
    // 611. 有效三角形的个数
    int triangleNumber(vector<int>& nums);
    // 621. 任务调度器
    int leastInterval(vector<char>& tasks, int n);
    // 661. 图片平滑器
    vector<vector<int>> imageSmoother(vector<vector<int>>& M);
    // 674. 最长连续递增序列
    int findLengthOfLCIS(vector<int>& nums);
    // 689. 三个无重叠子数组的最大和
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k);
    // 717. 1比特与2比特字符
    bool isOneBitCharacter(vector<int>& bits);
    // 729. 我的日程安排表 I
    vector<tuple<int, int, int>> startEndInterval;
    bool book(int start, int end);
    // 746. 使用最小花费爬楼梯
    int minCostClimbingStairs(vector<int>& cost);
    int _minCostClimbingStairs(vector<int> &cost, int n);
    // 768. 最多能完成排序的块
    int maxChunksToSorted(vector<int>& arr);
    // 769. 最多能完成排序的块 II
    int maxChunksToSortedII(vector<int>& arr);
    // 792. 匹配子序列的单词数
    int numMatchingSubseq(string S, vector<string>& words);
    // 795. 区间子数组个数
    int numSubarrayBoundedMax(vector<int>& A, int L, int R);
    // 830. 较大分组的位置
    vector<vector<int>> largeGroupPositions(string S);
    // 873. 最长的斐波那契子序列的长度
    int lenLongestFibSubseq(vector<int>& A);
    // 915. 分割数组
    int partitionDisjoint(vector<int>& A);
    // 926. 将字符串翻转到单调递增
    int minFlipsMonoIncr(string S);
    // 945. 使数组唯一的最小增量
    int minIncrementForUnique(vector<int>& A);
    // 974. Subarray Sums Divisible by K
    int subarraysDivByK(vector<int>& A, int K);
    // 989. Add to Array-Form of Integer
    vector<int> addToArrayForm(vector<int>& A, int K);
    // 1007. Minimum Domino Rotations For Equal Row
    int minDominoRotations(vector<int>& A, vector<int>& B);
    // 1010. Pairs of Songs With Total Durations Divisible by 60
    int numPairsDivisibleBy60(vector<int>& time);
    // 1014. Best Sightseeing Pair
    int maxScoreSightseeingPair(vector<int>& A);
    // 1018. Binary Prefix Divisible By 5
    vector<bool> prefixesDivBy5(vector<int>& A);

};

// 380. 常数时间插入、删除和获取随机元素
class RandomizedSet {
public:
    /** Initialize your data structure here. */
    unordered_map<int, bool> myMap;
    RandomizedSet() {
    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(myMap[val]) { return false; }
        myMap[val] = true;
        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(!myMap.count(val)) { return false; }
        myMap.erase(val);
        return true;
    }

    /** Get a random element from the set. */
    int getRandom() {
        auto iter = myMap.begin();
        int index = rand() % myMap.size();
        while(index){
            iter++;
            index--;
        }
        return (*iter).first;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

#endif //MYLEETCODE_MYLEETCODE_H
