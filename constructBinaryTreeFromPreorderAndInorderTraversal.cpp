//
// Created by 李研 on 2019/5/18.
//

#include "MyLeetCode.h"

/*
 * https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
 *【专题】Array；Tree；Depth-first Search
 */
TreeNode *MyLeetCode::buildTree(vector<int> &preorder, vector<int> &inorder) {
    if(preorder.empty()) { return nullptr; }
    int rootVal = preorder[0];
    auto root = new TreeNode(rootVal);
    auto rootIter = find(inorder.begin(), inorder.end(), rootVal);
    int dis = distance(inorder.begin(), rootIter);
    vector<int> lPreorder, rPreorder, lInorder, rInorder;
    lPreorder.assign(preorder.begin()+1, preorder.begin()+1+dis);
    rPreorder.assign(preorder.begin()+1+dis, preorder.end());
    lInorder.assign(inorder.begin(), rootIter);
    rInorder.assign(rootIter+1, inorder.end());
    root->left = buildTree(lPreorder, lInorder);
    root->right = buildTree(rPreorder, rInorder);
    return root;
}