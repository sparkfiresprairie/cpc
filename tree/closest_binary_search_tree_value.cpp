//
// Created by Xingyuan Wang on 3/8/17.
//

/*
    Given a non-empty binary search tree and a target value, find the value in the BST that
    is closest to the target.

    Note:
    Given target value is a floating point.
    You are guaranteed to have only one unique value in the BST that is closest to the target.
 */

#include "Tree.h"

int closestValue(TreeNode* root, double target) {
    if (!root) { throw; }
    int closest = root->val;
    while (root) {
        if (abs(root->val - target) < abs(closest - target)) {
            closest = root->val;
        }
        if (target < root->val) root = root->left;
        else root = root->right;
    }
    return closest;
}

// time: O(log n)
// space: O(1)