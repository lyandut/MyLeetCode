//
// Created by 李研 on 2019/7/27.
//

#include "MyLeetCode.h"

/*
 * 412. Fizz Buzz
 * https://leetcode-cn.com/problems/fizz-buzz/
 */

vector<string> MyLeetCode::fizzBuzz(int n) {
    vector<string> res(n, "");
    for(int i = 1; i<=n; ++i) {
        bool multiplesOfThree = (i % 3 == 0);
        bool multiplesOfFive = (i % 5 == 0);

        if(multiplesOfThree && multiplesOfFive) { res[i-1] = "FizzBuzz"; }
        else if(multiplesOfThree) { res[i-1] = "Fizz"; }
        else if(multiplesOfFive) {res[i-1] = "Buzz"; }
        else { res[i-1] = to_string(i); }
    }
    return res;
}