//
// Created by Xingyuan Wang on 3/17/17.
//

/*
    Given a binary tree where all the right nodes are either leaf nodes with a sibling
    (a left node that shares the same parent node) or empty, flip it upside down and
    turn it into a tree where the original right nodes turned into left leaf nodes.
    Return the new root.

    For example:
    Given a binary tree {1,2,3,4,5},
        1
       / \
      2   3
     / \
    4   5
    return the root of the binary tree [4,5,2,#,#,3,1].
       4
      / \
     5   2
        / \
       3   1
 */

#include "Tree.h"

TreeNode* upsideDownBinaryTree(TreeNode* root) {
    if (!root) return nullptr;
    stack<TreeNode*> s;
    TreeNode* t = root;
    while (t && t->left) {
        s.push(t);
        t = t->left;
    }
    root = t;
    while (!s.empty()) {
        t->left = s.top()->right;
        t->right = s.top();
        t = s.top();
        s.pop();
    }
    t->left = nullptr;
    t->right = nullptr;
    return root;
}

