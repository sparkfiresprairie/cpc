//
// Created by Xingyuan Wang on 3/28/17.
//


/*
    Given a binary tree, flatten it to a linked list in-place.

    For example,
    Given

             1
            / \
           2   5
          / \   \
         3   4   6
    The flattened tree should look like:
       1
        \
         2
          \
           3
            \
             4
              \
               5
                \
                 6
    click to show hints.

    Hints:
    If you notice carefully in the flattened tree, each node's right child points
    to the next node of a pre-order traversal.
 */

#include "Tree.h"

void flatten(TreeNode* root) {
    if (!root) return;
    flatten(root->left);
    flatten(root->right);
    TreeNode *tmp = root->right;
    root->right = root->left;
    root->left = nullptr;
    while (root->right)
        root = root->right;
    root->right = tmp;
}

// time: O(logn)
// space: O(logn) if considering stack