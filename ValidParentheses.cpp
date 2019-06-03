//
// Created by liyan on 2019-06-03.
//

/*
 * 20. Valid Parentheses
 * https://leetcode.com/problems/valid-parentheses/
 */

#include "MyLeetCode.h"
#include <stack>

bool MyLeetCode::isValid(string s) {
    stack<char> myStack;
    for(char ch : s){
        if(ch == '(' || ch == '[' || ch == '{'){
            myStack.push(ch);
        }
        else{
            if(myStack.empty()) { return false; }
            char top_ch = myStack.top();
            if(top_ch == '(' && ch == ')' || top_ch == '[' && ch == ']' || top_ch == '{' && ch == '}'){
                myStack.pop();
            }
            else{
                return false;
            }
        }
    }
    return myStack.empty();
}