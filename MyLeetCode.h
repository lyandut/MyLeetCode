//
// Created by liyan on 2018-12-31.
//

#ifndef MYLEETCODE_MYLEETCODE_H
#define MYLEETCODE_MYLEETCODE_H

#include <iostream>
#include <vector>
#include <string>
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
};

#endif //MYLEETCODE_MYLEETCODE_H
