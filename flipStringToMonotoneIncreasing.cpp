//
// Created by 李研 on 2020/2/9.
//

#include "MyLeetCode.h"

/*
 * 926. Flip String to Monotone Increasing
 * https://leetcode.com/problems/flip-string-to-monotone-increasing/
 * [tag] 数学
 */

int MyLeetCode::minFlipsMonoIncr(string S) {
    int zeroCount = count(S.begin(), S.end(), '0');
    int oneCount = count(S.begin(), S.end(), '1');
    int minCount = S.size();
    for (int i = 0; i < S.size() - 1; i++) {
        if (S[i] == '0' && S[i + 1] == '1') {
            // minCount = min(minCount, count(S.begin(), S.begin() + i, '1') + count(S.begin() + i + 2, S.end(), '0'));
            int totalCount = count(S.begin(), S.begin() + i, '1') + count(S.begin() + i + 2, S.end(), '0');
            minCount = minCount < totalCount ? minCount : totalCount;
        }
    }
    return min(min(zeroCount, oneCount), minCount);
}