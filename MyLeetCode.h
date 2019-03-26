//
// Created by liyan on 2018-12-31.
//

#ifndef MYLEETCODE_MYLEETCODE_H
#define MYLEETCODE_MYLEETCODE_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class MyLeetCode {
public:
    // 540. 有序数组中的单一元素
    int singleNonDuplicate(vector<int>& nums);
    // 392. 判断子序列
    bool isSubsequence(string s, string t);
    // 717. 1比特与2比特字符
    bool isOneBitCharacter(vector<int>& bits);
    // 287. 寻找重复数
    int findDuplicate(vector<int>& nums);
    // 926. 将字符串翻转到单调递增
    int minFlipsMonoIncr(string S);
    // 661. 图片平滑器
    vector<vector<int>> imageSmoother(vector<vector<int>>& M);
    // 268. 缺失数字
    int missingNumber(vector<int>& nums);
    // 830. 较大分组的位置
    vector<vector<int>> largeGroupPositions(string S);
    // 48. 旋转图像
    void rotate(vector<vector<int>>& matrix);
};

#endif //MYLEETCODE_MYLEETCODE_H
