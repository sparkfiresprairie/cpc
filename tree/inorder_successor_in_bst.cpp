//
// Created by Xingyuan Wang on 3/9/17.
//

/*
    Given a binary search tree and a node in it, find the in-order successor of
    that node in the BST.

    Note: If the given node has no in-order successor in the tree, return null.
 */

#include "Tree.h"

TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
    TreeNode* ancestor = nullptr;
    TreeNode* current = root;
    while (current) {
        if (current == p) break;
        if (p->val < current->val) {
            ancestor = current;
            current = current->left;
        } else {
            current = current->right;
        }
    }
    if (current->right) {
        current = current->right;
        while (current->left) current = current->left;
        return current;
    } else {
        return ancestor;
    }
}

// time: O(n)
// space: O(1)

