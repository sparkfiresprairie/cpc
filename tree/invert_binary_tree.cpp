//
// Created by Xingyuan Wang on 3/1/17.
//

/*
    Invert a binary tree.

         4
       /   \
      2     7
     / \   / \
    1   3 6   9

    to

         4
       /   \
      7     2
     / \   / \
    9   6 3   1
 */

#include "Tree.h"

TreeNode* invertTree(TreeNode* root) {
    if (!root) return nullptr;
    TreeNode* l = invertTree(root->left);
    TreeNode* r = invertTree(root->right);
    root->left = r;
    root->right = l;
    return root;
}