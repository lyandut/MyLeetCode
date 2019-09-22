//
// Created by liyan on 2019/9/22.
//

/*
 * 150. Evaluate Reverse Polish Notation
 * https://leetcode.com/problems/evaluate-reverse-polish-notation/
 */

#include "MyLeetCode.h"

int MyLeetCode::evalRPN(vector<string> &tokens) {
    stack<int> myStack;
    for(auto str : tokens) {
        if(str != "+" && str != "-" && str != "*" && str != "/") {
            myStack.push(stoi(str));
        }
        else {
            int second = myStack.top(); myStack.pop();
            int first = myStack.top(); myStack.pop();
            int result;
            switch (str[0]) {
                case '+':{
                    result = first + second;
                    break;
                }
                case '-':{
                    result = first - second;
                    break;
                }
                case '*':{
                    result = first * second;
                    break;
                }
                case '/':{
                    result = first / second;
                    break;
                }
                default:{
                    result = 0;
                    break;
                }
            }
            myStack.push(result);
        }
    }
    return myStack.size() == 1 ? myStack.top() : 0;
}