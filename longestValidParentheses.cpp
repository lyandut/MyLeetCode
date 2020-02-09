//
// Created by liyan on 2019/9/18.
//

/*
 * 32. Longest Valid Parentheses
 * https://leetcode.com/problems/longest-valid-parentheses/
 */

#include "MyLeetCode.h"

/*
 * 最长（连续）有效括号对
 */
int MyLeetCode::longestValidParentheses(string s){
    int longest = 0;
    // 使用 vector 模拟栈，存储接下来遇到的匹配括号的长度
    vector<int> stk;
    stk.push_back(0);
    for (auto ch : s) {
        if (ch == '(') {
            stk.push_back(0);
        }
        else {
            if (stk.size() > 1) {
                int v = stk.back(); stk.pop_back();
                // 取出第一个元素
                int lastCount = stk[stk.size() - 1];
                stk[stk.size() - 1] = lastCount + v + 2;
                longest = max(longest, stk[stk.size() - 1]);
            }
            else {
                stk.clear(); stk.push_back(0);
            }
        }
    }
    return longest;
}

/*
 * 有效括号对总数
 */
static int totalValidParentheses(string s) {
    stack<int> myStack;
    myStack.push(0);
    for(auto ch : s) {
        if(ch == '(') {
            myStack.push(0);
        }
        else {
            if(myStack.size() > 1){
                int curr = myStack.top() + 2; myStack.pop();
                int before = myStack.top(); myStack.pop();
                myStack.push(curr + before);
            }
        }
    }

    while (!myStack.empty()){
        if(myStack.top())
            return myStack.top();
        else
            myStack.pop();
    }
    return 0;
}