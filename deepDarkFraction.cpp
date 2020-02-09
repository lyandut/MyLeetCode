//
// Created by 李研 on 2020/2/9.
//

#include "MyLeetCode.h"

/*
 * LP 2. 分式化简
 * https://leetcode-cn.com/problems/deep-dark-fraction/
 */

vector<int> MyLeetCode::fraction(vector<int> &cont) {
    int fenzi = 1;
    int fenmu = cont.back();
    for (int i = cont.size() - 1; i > 0; --i) {
        int front = cont[i - 1];
        int curr = fenmu;
        fenmu = front * curr + fenzi;
        fenzi = curr;
    }
    return {fenmu, fenzi};
}