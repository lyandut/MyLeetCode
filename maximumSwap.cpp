//
// Created by liyan on 2019-05-23.
//

#include "MyLeetCode.h"

/*
 * 670. Maximum Swap
 * https://leetcode.com/problems/maximum-swap/
 */
int MyLeetCode::maximumSwap(int num) {
    string initStr = to_string(num);
    int numLength = initStr.size();
    if(numLength < 2) { return num; }
    string sortStr(initStr);
    sort(sortStr.begin(), sortStr.end(), [](char a, char b){return a > b;});
    int foundIndex = -1;
    for(int i=0; i<numLength; ++i){
        if(initStr[i] != sortStr[i]){
            foundIndex = i;
            break;
        }
    }
    if(foundIndex == -1) { return num; }
    for(int j=numLength-1; j>=0; --j){
        if(initStr[j] == sortStr[foundIndex]) {
            swap(initStr[j], initStr[foundIndex]);
            break;
        }
    }
    return stoi(initStr);
}