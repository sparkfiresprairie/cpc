//
// Created by Xingyuan Wang on 3/17/17.
//

/*
    Given a binary tree, count the number of uni-value subtrees.

    A Uni-value subtree means all nodes of the subtree have the same value.

    For example:
    Given binary tree,
                  5
                 / \
                1   5
               / \   \
              5   5   5
    return 4.
 */

#include "Tree.h"

bool isUnivalSubtrees(TreeNode* root, int& sum) {
    if (!root) return true;
    if (!root->left && !root->right) {
        ++sum;
        return true;
    }
    bool left = isUnivalSubtrees(root->left, sum);
    bool right = isUnivalSubtrees(root->right, sum);
    if (left && right && (!root->left || root->val == root->left->val) && (!root->right || root->val == root->right->val)) {
        ++sum;
        return true;
    } else {
        return false;
    }
}

int countUnivalSubtrees(TreeNode* root) {
    int sum = 0;
    isUnivalSubtrees(root, sum);
    return sum;
}

