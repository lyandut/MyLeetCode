//
// Created by 李研 on 2020/2/9.
//

#include "MyLeetCode.h"

/*
 * 392. Is Subsequence
 * https://leetcode.com/problems/is-subsequence/
 */

bool MyLeetCode::isSubsequence(string s, string t) {
    if (s.length() == 0 && t.length() == 0)
        return true;
    for (int i = 0, j = 0; j < t.length(); j++) {
        if (s[i] == t[j])
            i++;
        if (i == s.length())
            return true;
    }
    return false;
}