//
// Created by 李研 on 2020/2/10.
//

#include "MyLeetCode.h"

/*
 * 974. Subarray Sums Divisible by K
 * https://leetcode.com/problems/subarray-sums-divisible-by-k/
 *【专题】Array；Hash Table
 */

int MyLeetCode::subarraysDivByK(vector<int> &A, int K) {
    int res = 0;
    vector<int> subArraySum(A.size() + 1, 0);
    vector<int> hashTable(K, 0);
    hashTable[(subArraySum[0] % K + K) % K]++;
    for (int i = 0; i < A.size(); i++) {
        subArraySum[i + 1] = subArraySum[i] + A[i];
        hashTable[(subArraySum[i + 1] % K + K) % K]++;
    }
    for (auto each : hashTable) {
        res += each * (each - 1) / 2;
    }
    return res;
}