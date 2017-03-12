//
// Created by Xingyuan Wang on 3/11/17.
//

/*
    Given a binary tree, find the length of the longest consecutive sequence path.

    The path refers to any sequence of nodes from some starting node to any node in the tree
    along the parent-child connections. The longest consecutive path need to be from parent
    to child (cannot be the reverse).

    For example,
       1
        \
         3
        / \
       2   4
            \
             5
    Longest consecutive sequence path is 3-4-5, so return 3.
       2
        \
         3
        /
       2
      /
     1
    Longest consecutive sequence path is 2-3,not3-2-1, so return 2.
 */

#include "Tree.h"

int help(TreeNode* self, TreeNode* parent, int len) {
    if (!self) return 0;
    if (parent && parent->val + 1 == self->val) ++len;
    else len = 1;
    int l_len = help(self->left, self, len);
    int r_len = help(self->right, self, len);
    return max(len, max(l_len, r_len));
}

int longestConsecutive(TreeNode* root) {
    return help(root, nullptr, 0);
}

// time: O(n)
// space: O(logn)
