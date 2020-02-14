//
// Created by liyan on 2018-12-31.
//

#ifndef MYLEETCODE_MYLEETCODE_H
#define MYLEETCODE_MYLEETCODE_H

#include "DataStructureAndAlgorithm.h"

class MyLeetCode {
public:
    // 1. 两数之和
    static vector<int> twoSum(vector<int> &nums, int target);

    // 11. 盛最多水的容器
    static int maxArea(vector<int> &height);

    // 15. 三数之和
    static vector<vector<int>> threeSum(vector<int> &nums);

    // 20. 有效的括号
    static bool isValid(string s);

    // 21. 合并两个有序链表
    static ListNode *mergeTwoLists(ListNode *l1, ListNode *l2);

    // 23. 合并K个排序链表
    static ListNode *mergeKLists(vector<ListNode *> &lists);

    // 24. 两两交换链表中的节点
    static ListNode *swapPairs(ListNode *head);

    // 25. K 个一组翻转链表
    static ListNode *reverseKGroup(ListNode *head, int k);

    // 26. 删除排序数组中的重复项
    static int removeDuplicates(vector<int> &nums);

    // 27. 移除元素
    static int removeElement(vector<int> &nums, int val);

    // 31. 下一个排列
    static void nextPermutation(vector<int> &nums);

    // 32. 最长有效括号
    static int longestValidParentheses(string s);

    // 33. 搜索旋转排序数组
    static int search(vector<int> &nums, int target);

    // 35. 搜索插入位置
    static int searchInsert(vector<int> &nums, int target);

    // 39. 组合总和
    static vector<vector<int>> combinationSum(vector<int> &candidates, int target);

    // 40. 组合总和 II
    static vector<vector<int>> combinationSum2(vector<int> &candidates, int target);

    // 41. 缺失的第一个正数
    static int firstMissingPositive(vector<int> &nums);

    // 48. 旋转图像
    static void rotate(vector<vector<int>> &matrix);

    // 51. N皇后
    static vector<vector<string>> solveNQueens(int n);

    // 53. 最大子序和
    static int maxSubArray(vector<int> &nums);

    // 56. 合并区间
    static vector<vector<int>> merge(vector<vector<int>> &intervals);

    // 59. 螺旋矩阵 II
    static vector<vector<int>> generateMatrix(int n);

    // 61. 旋转链表
    static ListNode *rotateRight(ListNode *head, int k);

    // 62. 不同路径
    static int uniquePaths(int m, int n);

    // 64. 最小路径和
    static int minPathSum(vector<vector<int>> &grid);

    // 66. 加一
    static vector<int> plusOne(vector<int> &digits);

    // 74. 搜索二维矩阵
    static bool searchMatrix(vector<vector<int>> &matrix, int target);

    // 75. 颜色分类
    static void sortColors(vector<int> &nums);

    // 73. 矩阵置零
    static void setZeroes(vector<vector<int>> &matrix);

    // 78. 子集
    static vector<vector<int>> subsets(vector<int> &nums);

    // 80. 删除排序数组中的重复项 II
    static int removeDuplicatesII(vector<int> &nums);

    // 81. 搜索旋转排序数组 II
    static bool searchII(vector<int> &nums, int target);

    // 88. 合并两个有序数组
    static void merge(vector<int> &nums1, int m, vector<int> &nums2, int n);

    // 90. 子集 II
    static vector<vector<int>> subsetsWithDup(vector<int> &nums);

    // 92. 反转链表 II
    static ListNode *reverseBetween(ListNode *curr, int m, int n);

    // 105. 从前序与中序遍历序列构造二叉树
    static TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder);

    // 106. 从中序与后序遍历序列构造二叉树
    static TreeNode *buildTree2(vector<int> &inorder, vector<int> &postorder);

    // 118. 杨辉三角
    static vector<vector<int>> generate(int numRows);

    // 119. 杨辉三角 II
    static vector<int> getRow(int rowIndex);

    // 120. 三角形最小路径和
    static int minimumTotal(vector<vector<int>> &triangle);

    // 121. 买卖股票的最佳时机
    static int maxProfit(vector<int> &prices);

    // 122. 买卖股票的最佳时机 II
    static int maxProfitII(vector<int> &prices);

    // 123. 买卖股票的最佳时机 III
    static int maxProfitIII(vector<int> &prices);

    // 128. 最长连续序列
    static int longestConsecutive(vector<int> &nums);

    // 136. 只出现一次的数字
    static int singleNumber(vector<int> &nums);

    // 141. 环形链表
    static bool hasCycle(ListNode *head);

    // 142. 环形链表 II
    static ListNode *detectCycle(ListNode *head);

    // 150. 逆波兰表达式求值
    static int evalRPN(vector<string> &tokens);

    // 153. 寻找旋转排序数组中的最小值
    static int findMin(vector<int> &nums);

    // 154. 寻找旋转排序数组中的最小值 II
    static int findMinII(vector<int> &nums);

    // 162. 寻找峰值
    static int findPeakElement(vector<int> &nums);

    // 169. 求众数
    static int majorityElement(vector<int> &nums);

    // 188. 买卖股票的最佳时机 IV
    static int maxProfitIV(int k, vector<int> &prices);

    // 198. 打家劫舍
    static int rob(vector<int> &nums);

    // 206. 反转链表
    static ListNode *reverseList(ListNode *head);

    // 207. 课程表
    static bool canFinish(int numCourses, vector<vector<int>> &prerequisites);

    // 210. 课程表 II
    static vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites);

    // 215. 数组中的第K个最大元素
    static int findKthLargest(vector<int> &nums, int k);

    // 239. 滑动窗口最大值
    static vector<int> maxSlidingWindow(vector<int> &nums, int k);

    // 268. 缺失数字
    static int missingNumber(vector<int> &nums);

    // 287. 寻找重复数
    static int findDuplicate(vector<int> &nums);

    // 312. 戳气球
    static int maxCoins(vector<int> &nums);

    // 315. 计算右侧小于当前元素的个数
    static vector<int> countSmaller(vector<int> &nums);

    // 392. 判断子序列
    static bool isSubsequence(string s, string t);

    // 394. 字符串解码
    static string decodeString(string s);

    // 412. Fizz Buzz
    static vector<string> fizzBuzz(int n);

    // 416. 分割等和子集
    static bool canPartition(vector<int> &nums);

    // 442. 数组中重复的数据
    static vector<int> findDuplicates(vector<int> &nums);

    // 540. 有序数组中的单一元素
    static int singleNonDuplicate(vector<int> &nums);

    // 547. 朋友圈
    static int findCircleNum(vector<vector<int>> &M);

    // 560. 和为K的子数组
    static int subarraySum(vector<int> &nums, int k);

    // 589. N叉树的前序遍历
    static vector<int> preorder(Node *root);

    // 611. 有效三角形的个数
    static int triangleNumber(vector<int> &nums);

    // 621. 任务调度器
    static int leastInterval(vector<char> &tasks, int n);

    // 643. 子数组最大平均数 I
    static double findMaxAverage(vector<int> &nums, int k);

    // 661. 图片平滑器
    static vector<vector<int>> imageSmoother(vector<vector<int>> &M);

    // 670. 最大交换
    static int maximumSwap(int num);

    // 674. 最长连续递增序列
    static int findLengthOfLCIS(vector<int> &nums);

    // 689. 三个无重叠子数组的最大和
    static vector<int> maxSumOfThreeSubarrays(vector<int> &nums, int k);

    // 695. 岛屿的最大面积
    static int maxAreaOfIsland(vector<vector<int>> &grid);

    // 713. 乘积小于K的子数组
    static int numSubarrayProductLessThanK(vector<int> &nums, int k);

    // 717. 1比特与2比特字符
    static bool isOneBitCharacter(vector<int> &bits);

    // 724. 寻找数组的中心索引
    static int pivotIndex(vector<int> &nums);

    // 746. 使用最小花费爬楼梯
    static int minCostClimbingStairs(vector<int> &cost);

    // 747. 至少是其他数字两倍的最大数
    static int dominantIndex(vector<int> &nums);

    // 768. 最多能完成排序的块
    static int maxChunksToSorted(vector<int> &arr);

    // 769. 最多能完成排序的块 II
    static int maxChunksToSortedII(vector<int> &arr);

    // 775. 全局倒置与局部倒置
    static bool isIdealPermutation(vector<int> &A);

    // 782. 变为棋盘
    static int movesToChessboard(vector<vector<int>> &board);

    // 792. 匹配子序列的单词数
    static int numMatchingSubseq(string S, vector<string> &words);

    // 795. 区间子数组个数
    static int numSubarrayBoundedMax(vector<int> &A, int L, int R);

    // 825. 适龄的朋友
    static int numFriendRequests(vector<int> &ages);

    // 830. 较大分组的位置
    static vector<vector<int>> largeGroupPositions(string S);

    // 849. 到最近的人的最大距离
    static int maxDistToClosest(vector<int> &seats);

    // 852. 山脉数组的峰顶索引
    static int peakIndexInMountainArray(vector<int> &A);

    // 870. 优势洗牌
    static vector<int> advantageCount(vector<int> &A, vector<int> &B);

    // 873. 最长的斐波那契子序列的长度
    static int lenLongestFibSubseq(vector<int> &A);

    // 905. 按奇偶排序数组
    static vector<int> sortArrayByParity(vector<int> &A);

    // 915. 分割数组
    static int partitionDisjoint(vector<int> &A);

    // 922. 按奇偶排序数组 II
    static vector<int> sortArrayByParityII(vector<int> &A);

    // 926. 将字符串翻转到单调递增
    static int minFlipsMonoIncr(string S);

    // 945. 使数组唯一的最小增量
    static int minIncrementForUnique(vector<int> &A);

    // 974. Subarray Sums Divisible by K
    static int subarraysDivByK(vector<int> &A, int K);

    // 977. 有序数组的平方
    static vector<int> sortedSquares(vector<int> &A);

    // 989. Add to Array-Form of Integer
    static vector<int> addToArrayForm(vector<int> &A, int K);

    // 1007. Minimum Domino Rotations For Equal Row
    static int minDominoRotations(vector<int> &A, vector<int> &B);

    // 1010. Pairs of Songs With Total Durations Divisible by 60
    static int numPairsDivisibleBy60(vector<int> &time);

    // 1014. Best Sightseeing Pair
    static int maxScoreSightseeingPair(vector<int> &A);

    // 1018. Binary Prefix Divisible By 5
    static vector<bool> prefixesDivBy5(vector<int> &A);

    // 1036. 逃离大迷宫
    static bool isEscapePossible(vector<vector<int>> &blocked, vector<int> &source, vector<int> &target);

    // 2019 力扣杯全国秋季编程大赛
    // LCP 2. 分式化简
    static vector<int> fraction(vector<int> &cont);

    // LCP 3. 机器人大冒险
    static bool robot(string command, vector<vector<int>> &obstacles, int x, int y);

    // LCP 5. 发 LeetCoin
    static vector<int> bonus(int n, vector<vector<int>> &leadership, vector<vector<int>> &operations);
};


#endif //MYLEETCODE_MYLEETCODE_H
