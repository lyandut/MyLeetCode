//
// Created by 李研 on 2020/2/10.
//

#include "MyLeetCode.h"

/*
 * 792. Number of Matching Subsequences
 * https://leetcode.com/problems/number-of-matching-subsequences/
 *【专题】Array
 */

int MyLeetCode::numMatchingSubseq(string S, vector<string> &words) {
    int count = 0;
    unordered_map<char, vector<int>> hashMap;
    for (int i = 0; i < S.size(); i++) {
        hashMap[S[i]].push_back(i);
    }
    for (string &word : words) {
        if (hashMap[word[0]].empty()) { continue; }
        int currIndex = hashMap[word[0]][0];
        int j;
        for (j = 1; j < word.size(); j++) {
            if (hashMap[word[j]].empty()) { break; }
            int oldIndex = currIndex;
            for (int hashIndex : hashMap[word[j]]) {
                if (hashIndex > currIndex) {
                    currIndex = hashIndex;
                    break;
                }
            }
            if (currIndex == oldIndex) { break; }
        }
        if (j == word.size()) { count++; }
    }
    return count;
}