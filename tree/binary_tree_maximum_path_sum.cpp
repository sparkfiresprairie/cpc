//
// Created by Xingyuan Wang on 3/13/17.
//

/*
    Given a binary tree, find the maximum path sum.

    For this problem, a path is defined as any sequence of nodes from some starting
    node to any node in the tree along the parent-child connections. The path must
    contain at least one node and does not need to go through the root.

    For example:
    Given the below binary tree,

           1
          / \
         2   3
    Return 6.
 */

#include "Tree.h"

int maxPathSum(TreeNode* root) {
    int ans = INT_MIN;
    help(root, ans);
    return ans;
}

int help(TreeNode* root, int& ans) {
    if (!root) return 0;
    int left = max(0, help(root->left, ans));
    int right = max(0, help(root->right, ans));
    ans = max(ans, root->val + left + right);
    return root->val + max(left, right);
}