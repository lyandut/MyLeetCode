//
// Created by 李研 on 2019/6/4.
//

/*
 * 106. Construct Binary Tree from Inorder and Postorder Traversal
 * https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
 */

#include "MyLeetCode.h"

TreeNode *MyLeetCode::buildTree2(vector<int> &inorder, vector<int> &postorder) {
    if(postorder.empty()) { return nullptr; }
    int rootVal = postorder[postorder.size()-1];
    auto root = new TreeNode(rootVal);
    auto rootIter = find(inorder.begin(), inorder.end(), rootVal);
    int dis = distance(inorder.begin(), rootIter);
    vector<int> lPostorder, rPostorder, lInorder, rInorder;
    lPostorder.assign(postorder.begin(), postorder.begin()+dis);
    rPostorder.assign(postorder.begin()+dis, postorder.end()-1);
    lInorder.assign(inorder.begin(), rootIter);
    rInorder.assign(rootIter+1, inorder.end());
    root->left = buildTree(lInorder, lPostorder);
    root->right = buildTree(rInorder, rPostorder);
    return root;
}
