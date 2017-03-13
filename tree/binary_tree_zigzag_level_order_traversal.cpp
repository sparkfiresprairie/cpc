//
// Created by Xingyuan Wang on 3/13/17.
//

/*
    Given a binary tree, return the zigzag level order traversal of its nodes' values.
    (ie, from left to right, then right to left for the next level and alternate between).

    For example:
    Given binary tree [3,9,20,null,null,15,7],
        3
       / \
      9  20
        /  \
       15   7
    return its zigzag level order traversal as:
    [
      [3],
      [20,9],
      [15,7]
    ]
 */

#include "Tree.h"

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    queue<TreeNode*> q;
    if (root) q.push(root);
    int depth = 0;
    while (!q.empty()) {
        vector<int> level;
        int sz = q.size();
        for (int i = 0; i < sz; ++i) {
            TreeNode* t = q.front();
            q.pop();
            level.push_back(t->val);
            if (t->left) q.push(t->left);
            if (t->right) q.push(t->right);
        }
        if (depth % 2 == 1) reverse(level.begin(), level.end());
        ans.push_back(level);
        ++depth;
    }
    return ans;
}

// time: O(n)
// space: O(n)