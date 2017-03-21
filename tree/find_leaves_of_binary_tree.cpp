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

int help(TreeNode* root, vector<vector<int>>& leaves) {
    if (!root) return 0;
    int level = max(help(root->left, leaves), help(root->right, leaves)) + 1;
    if (level > leaves.size()) leaves.push_back({});
    leaves[level - 1].push_back(root->val);
    return level;
}

vector<vector<int>> findLeaves(TreeNode* root) {
    vector<vector<int>> leaves;
    help(root, leaves);
    return leaves;
}

// time: O(n)
// space: O(log n)
