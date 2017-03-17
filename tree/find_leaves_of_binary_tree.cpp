//
// Created by Xingyuan Wang on 3/17/17.
//

/*
    Given a binary tree, collect a tree's nodes as if you were doing this:
    Collect and remove all leaves, repeat until the tree is empty.

    Example:
    Given binary tree
              1
             / \
            2   3
           / \
          4   5
    Returns [4, 5, 3], [2], [1].

    Explanation:
    1. Removing the leaves [4, 5, 3] would result in this tree:

              1
             /
            2
    2. Now removing the leaf [2] would result in this tree:

              1
    3. Now removing the leaf [1] would result in the empty tree:

              []
    Returns [4, 5, 3], [2], [1].
 */

#include "Tree.h"

int help(TreeNode* root, vector<vector<int>>& ans) {
    if (!root) return 0;
    int level = max(help(root->left, ans), help(root->right, ans)) + 1;
    if (level > ans.size()) ans.push_back({});
    ans[level - 1].push_back(root->val);
    return level;
}

vector<vector<int>> findLeaves(TreeNode* root) {
    vector<vector<int>> ans;
    help(root, ans);
    return ans;
}
