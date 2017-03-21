//
// Created by Xingyuan Wang on 3/20/17.
//

/*
    The thief has found himself a new place for his thievery again. There is only
    one entrance to this area, called the "root." Besides the root, each house has
    one and only one parent house. After a tour, the smart thief realized that "all
    houses in this place forms a binary tree". It will automatically contact the
    police if two directly-linked houses were broken into on the same night.

    Determine the maximum amount of money the thief can rob tonight without alerting
    the police.

    Example 1:
         3
        / \
       2   3
        \   \
         3   1
    Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
    Example 2:
         3
        / \
       4   5
      / \   \
     1   3   1
    Maximum amount of money the thief can rob = 4 + 5 = 9.
 */

#include "Tree.h"

int rob(TreeNode* root) {
    vector<int> ans = help(root);
    return max(ans[0], ans[1]);
}

// rob(root) as a new function which will return an array of two elements,
// the first element of which denotes the maximum amount of money that can be robbed if root is not robbed,
// while the second element signifies the maximum amount of money robbed if it is robbed.
vector<int> help(TreeNode* root) {
    vector<int> ans(2, 0);
    if (!root) return ans;

    vector<int> left = help(root->left);
    vector<int> right = help(root->right);
    ans[0] = max(left[0], left[1]) + max(right[0], right[1]);
    ans[1] = root->val + left[0] + right[0];
    return ans;
}

// time: O(n)
// space: O(logn)