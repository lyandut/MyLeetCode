//
// Created by 李研 on 2020/2/9.
//

#include "MyLeetCode.h"

/*
 * 717. 1-bit and 2-bit Characters
 * https://leetcode.com/problems/1-bit-and-2-bit-characters/
 * [tag] 数学
 */

bool MyLeetCode::isOneBitCharacter(vector<int> &bits) {
    auto iter = bits.rbegin() + 1;
    int count = 0;
    while (iter != bits.rend()) {
        if ((*iter) == 1)
            count++;
        else
            break;
        ++iter;
    }
    bool flag = count % 2 == 0;
    return flag;
}