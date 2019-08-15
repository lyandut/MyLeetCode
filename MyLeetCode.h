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

/* Definition for singly-linked list. */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/* Definition for a binary tree node. */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class MyLeetCode {
public:
    // 1. 两数之和
    vector<int> twoSum(vector<int>& nums, int target);
    // 11. 盛最多水的容器
    int maxArea(vector<int>& height);
    // 15. 三数之和
    vector<vector<int>> threeSum(vector<int>& nums);
    // 20. 有效的括号
    bool isValid(string s);
    // 21. 合并两个有序链表
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2);
    // 23. 合并K个排序链表
    ListNode* mergeKLists(vector<ListNode*>& lists);
    // 25. K 个一组翻转链表
    ListNode* reverseKGroup(ListNode* head, int k);
    // 26. 删除排序数组中的重复项
    int removeDuplicates(vector<int>& nums);
    // 27. 移除元素
    int removeElement(vector<int>& nums, int val);
    // 31. 下一个排列
    void nextPermutation(vector<int>& nums);
    // 33. 搜索旋转排序数组
    int search(vector<int>& nums, int target);
    // 35. 搜索插入位置
    int searchInsert(vector<int>& nums, int target);
    // 39. 组合总和
    vector<vector<int>> combinationSum(vector<int>& candidates, int target);
    void _combinationSum(vector<int> &candidates, int target, vector<vector<int>> &res, vector<int> &curr, int index);
    // 40. 组合总和 II
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target);
    void _combinationSum2(vector<int> &candidates, int target, vector<vector<int>> &res, vector<int> &curr, int index);
    // 41. 缺失的第一个正数
    int firstMissingPositive(vector<int>& nums);
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
    // 66. 加一
    vector<int> plusOne(vector<int>& digits);
    // 74. 搜索二维矩阵
    bool searchMatrix(vector<vector<int>>& matrix, int target);
    // 75. 颜色分类
    void sortColors(vector<int>& nums);
    // 73. 矩阵置零
    void setZeroes(vector<vector<int>>& matrix);
    // 78. 子集
    vector<vector<int>> subsets(vector<int>& nums);
    // 80. 删除排序数组中的重复项 II
    int removeDuplicatesII(vector<int>& nums);
    // 81. 搜索旋转排序数组 II
    bool searchII(vector<int>& nums, int target);
    // 88. 合并两个有序数组
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n);
    // 90. 子集 II
    vector<vector<int>> subsetsWithDup(vector<int>& nums);
    // 92. 反转链表 II
    ListNode* reverseBetween(ListNode* curr, int m, int n);
    // 105. 从前序与中序遍历序列构造二叉树
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder);
    // 106. 从中序与后序遍历序列构造二叉树
    TreeNode* buildTree2(vector<int>& inorder, vector<int>& postorder);
    // 118. 杨辉三角
    vector<vector<int>> generate(int numRows);
    // 119. 杨辉三角 II
    vector<int> getRow(int rowIndex);
    // 120. 三角形最小路径和
    int minimumTotal(vector<vector<int>>& triangle);
    // 121. 买卖股票的最佳时机
    int maxProfit(vector<int>& prices);
    // 128. 最长连续序列
    int longestConsecutive(vector<int>& nums);
    // 136. 只出现一次的数字
    int singleNumber(vector<int>& nums);
    // 141. 环形链表
    bool hasCycle(ListNode *head);
    // 142. 环形链表 II
    ListNode *detectCycle(ListNode *head);
    // 153. 寻找旋转排序数组中的最小值
    int findMin(vector<int>& nums);
    // 154. 寻找旋转排序数组中的最小值 II
    int findMinII(vector<int>& nums);
    // 162. 寻找峰值
    int findPeakElement(vector<int>& nums);
    // 169. 求众数
    int majorityElement(vector<int>& nums);
    // 206. 反转链表
    ListNode* reverseList(ListNode* head);
    // 215. 数组中的第K个最大元素
    int findKthLargest(vector<int>& nums, int k);
    int _quickSelect(vector<int> nums, int left, int right, int k);
    // 268. 缺失数字
    int missingNumber(vector<int>& nums);
    // 287. 寻找重复数
    int findDuplicate(vector<int>& nums);
    // 392. 判断子序列
    bool isSubsequence(string s, string t);
    // 394. 字符串解码
    string decodeString(string s);
    // 412. Fizz Buzz
    vector<string> fizzBuzz(int n);
    // 442. 数组中重复的数据
    vector<int> findDuplicates(vector<int>& nums);
    // 540. 有序数组中的单一元素
    int singleNonDuplicate(vector<int>& nums);
    // 560. 和为K的子数组
    int subarraySum(vector<int>& nums, int k);
    // 611. 有效三角形的个数
    int triangleNumber(vector<int>& nums);
    // 621. 任务调度器
    int leastInterval(vector<char>& tasks, int n);
    // 643. 子数组最大平均数 I
    double findMaxAverage(vector<int>& nums, int k);
    // 661. 图片平滑器
    vector<vector<int>> imageSmoother(vector<vector<int>>& M);
    // 670. 最大交换
    int maximumSwap(int num);
    // 674. 最长连续递增序列
    int findLengthOfLCIS(vector<int>& nums);
    // 689. 三个无重叠子数组的最大和
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k);
    // 713. 乘积小于K的子数组
    int numSubarrayProductLessThanK(vector<int>& nums, int k);
    // 717. 1比特与2比特字符
    bool isOneBitCharacter(vector<int>& bits);
    // 724. 寻找数组的中心索引
    int pivotIndex(vector<int>& nums);
    // 729. 我的日程安排表 I
    vector<tuple<int, int, int>> startEndInterval;
    bool book(int start, int end);
    // 746. 使用最小花费爬楼梯
    int minCostClimbingStairs(vector<int>& cost);
    int _minCostClimbingStairs(vector<int> &cost, int n);
    // 747. 至少是其他数字两倍的最大数
    int dominantIndex(vector<int>& nums);
    // 768. 最多能完成排序的块
    int maxChunksToSorted(vector<int>& arr);
    // 769. 最多能完成排序的块 II
    int maxChunksToSortedII(vector<int>& arr);
    // 775. 全局倒置与局部倒置
    bool isIdealPermutation(vector<int>& A);
    // 782. 变为棋盘
    int movesToChessboard(vector<vector<int>>& board);
    bool isOpposite(vector<int> &A, vector<int> &B);
    int calculate(vector<int> &A, int countZero, int countOne);
    // 792. 匹配子序列的单词数
    int numMatchingSubseq(string S, vector<string>& words);
    // 795. 区间子数组个数
    int numSubarrayBoundedMax(vector<int>& A, int L, int R);
    // 825. 适龄的朋友
    int numFriendRequests(vector<int>& ages);
    // 830. 较大分组的位置
    vector<vector<int>> largeGroupPositions(string S);
    // 849. 到最近的人的最大距离
    int maxDistToClosest(vector<int>& seats);
    // 852. 山脉数组的峰顶索引
    int peakIndexInMountainArray(vector<int>& A);
    // 870. 优势洗牌
    vector<int> advantageCount(vector<int>& A, vector<int>& B);
    // 873. 最长的斐波那契子序列的长度
    int lenLongestFibSubseq(vector<int>& A);
    // 905. 按奇偶排序数组
    vector<int> sortArrayByParity(vector<int>& A);
    // 915. 分割数组
    int partitionDisjoint(vector<int>& A);
    // 922. 按奇偶排序数组 II
    vector<int> sortArrayByParityII(vector<int>& A);
    // 926. 将字符串翻转到单调递增
    int minFlipsMonoIncr(string S);
    // 945. 使数组唯一的最小增量
    int minIncrementForUnique(vector<int>& A);
    // 974. Subarray Sums Divisible by K
    int subarraysDivByK(vector<int>& A, int K);
    // 977. 有序数组的平方
    vector<int> sortedSquares(vector<int>& A);
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


#endif //MYLEETCODE_MYLEETCODE_H
