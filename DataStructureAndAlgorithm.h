//
// Created by 李研 on 2020/2/10.
//

#ifndef MYLEETCODE_DATASTRUCTUREANDALGORITHM_H
#define MYLEETCODE_DATASTRUCTUREANDALGORITHM_H

#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <cstring>
#include <stack>
#include <queue>
#include <deque>
#include <list>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <tuple>
#include <algorithm>
#include <numeric>
#include <cmath>

using namespace std;

/* Definition for singly-linked list. */
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

/* Definition for a binary tree node. */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/* Definition for a trie node. */
struct TrieNode {
    bool isWord;
    TrieNode *children[26];

    TrieNode() : isWord(false) {
        memset(children, 0, sizeof(children));
    }
};

/* Definition for a Node. */
class Node {
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node *> _children) {
        val = _val;
        children = _children;
    }
};

/* Definition for Binary Index Tree. */
class FenwickTree {
public:
    FenwickTree(int n) : _partial_sum(n + 1, 0) {}

    FenwickTree(const vector<int> &nums) : FenwickTree(nums.size()) {
        for (int i = 0; i < nums.size(); ++i)
            update(i + 1, nums[i]);
    }

    void update(int i, int delta) {
        while (i < _partial_sum.size()) {
            _partial_sum[i] += delta;
            i += lowbit(i); // 更新树：父节点index = 子节点index + lowbit(子节点index)
        }
    }

    int query(int i) const {
        int prefix_sum = 0;
        while (i > 0) {
            prefix_sum += _partial_sum[i];
            i -= lowbit(i); // 查找树：父节点index = 子节点index - lowbit(子节点index)
        }
        return prefix_sum;
    }

private:
    static inline int lowbit(int i) { return i & (-i); }

private:
    vector<int> _partial_sum;
};

#endif //MYLEETCODE_DATASTRUCTUREANDALGORITHM_H
