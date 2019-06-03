//
// Created by liyan on 2019-06-03.
//

/*
 * 394. Decode String
 * https://leetcode.com/problems/decode-string/
 */

#include "MyLeetCode.h"
#include <stack>

string MyLeetCode::decodeString(string s) {
    stack<char> myStack;
    for(char ch : s){
        if(ch == ']'){
            string subString;
            while(myStack.top() != '['){
                subString = myStack.top() + subString;
                myStack.pop();
            }
            myStack.pop();  // pop '['

            string countString;
            while(!myStack.empty() && myStack.top() >= '0' && myStack.top() <= '9'){
                countString = myStack.top() + countString;
                myStack.pop();
            }
            int count = stoi(countString);
            for(int i=0; i<count; ++i){
                for(char subCh : subString){
                    myStack.push(subCh);
                }
            }
        }
        else{
            myStack.push(ch);
        }
    }

    string resString;
    while (!myStack.empty()){
        resString = myStack.top() + resString;
        myStack.pop();
    }
    return resString;
}