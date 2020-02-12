//
// Created by 李研 on 2020/2/10.
//

#ifndef MYLEETCODE_DATASTRUCTUREDEFINITION_H
#define MYLEETCODE_DATASTRUCTUREDEFINITION_H

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <stack>
#include <deque>
#include <list>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <tuple>
#include <algorithm>
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

#endif //MYLEETCODE_DATASTRUCTUREDEFINITION_H
