//
// Created by Xingyuan Wang on 3/13/17.
//

/*
    Given a binary tree, imagine yourself standing on the right side of it,
    return the values of the nodes you can see ordered from top to bottom.

    For example:
    Given the following binary tree,
       1            <---
     /   \
    2     3         <---
     \     \
      5     4       <---
    You should return [1, 3, 4].
 */

#include "Tree.h"

vector<int> rightSideView(TreeNode* root) {
        vector<int> ret;
        queue<TreeNode*> q;
        if (root) q.push(root);
        while (!q.empty()) {
            int num = q.size();
            for (int i = 0; i < num; i += 1) {
                TreeNode* t = q.front();
                q.pop();
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
                if (i == num - 1) ret.push_back(t->val);
            }
        }
        return ret;
    }