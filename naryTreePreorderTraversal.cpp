//
// Created by 李研 on 2020/2/10.
//

#include "MyLeetCode.h"

/*
 * 589. N-ary Tree Preorder Traversal
 * https://leetcode.com/problems/n-ary-tree-preorder-traversal/
 * [专题] 递归
 */

/*
 * 1. 递归
 */
//static void recursion(vector<int> &res, Node *curr) {
//    if (curr == nullptr) return;
//    res.push_back(curr->val);
//    for (auto each : curr->children) {
//        recursion(res, each);
//    }
//}
//
//vector<int> MyLeetCode::preorder(Node *root) {
//    vector<int> res;
//    recursion(res, root);
//    return res;
//}

/*
 * 2. 用stack转递归代码
 */
vector<int> MyLeetCode::preorder(Node *root) {
    vector<int> res;
    if (root == nullptr)
        return res;

    stack<Node *> stk;
    stk.push(root);
    while (!stk.empty()) {
        Node *top_node = stk.top();
        stk.pop();
        res.push_back(top_node->val);
        for (auto r_iter = top_node->children.rbegin(); r_iter != top_node->children.rend(); ++r_iter) {
            if ((*r_iter) != nullptr)
                stk.push(*r_iter);
        }
    }
    return res;
}