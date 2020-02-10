//
// Created by 李研 on 2020/2/10.
//

#include "MyLeetCode.h"

/*
 * 1010. Pairs of Songs With Total Durations Divisible by 60
 * https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/
 *【专题】Array
 */

int MyLeetCode::numPairsDivisibleBy60(vector<int> &time) {
    int count = 0;
    int mod[60] = {0};
    for (int each : time) {
        mod[each % 60]++;
    }
    for (int i = 1; i < 30; i++) {
        count += mod[i] * mod[60 - i];
    }
    count += mod[0] * (mod[0] - 1) / 2;
    count += mod[30] * (mod[30] - 1) / 2;
    return count;
}