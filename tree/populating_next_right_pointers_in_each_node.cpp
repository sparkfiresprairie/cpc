//
// Created by Xingyuan Wang on 3/26/17.
//

/*
    Given a binary tree

        struct TreeLinkNode {
          TreeLinkNode *left;
          TreeLinkNode *right;
          TreeLinkNode *next;
        }
    Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

    Initially, all next pointers are set to NULL.

    Note:

    You may only use constant extra space.
    You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).
    For example,
    Given the following perfect binary tree,
             1
           /  \
          2    3
         / \  / \
        4  5  6  7
    After calling your function, the tree should look like:
             1 -> NULL
           /  \
          2 -> 3 -> NULL
         / \  / \
        4->5->6->7 -> NULL
 */

#include "Tree.h"

void connect(TreeLinkNode *root) {
    queue<TreeLinkNode*> q;
    if (root) q.push(root);
    while (!q.empty()) {
        int num = q.size();
        for (int i = 0; i < num; ++i) {
            TreeLinkNode* t = q.front();
            q.pop();
            if (i < num - 1) t->next = q.front();
            if (t->left) q.push(t->left);
            if (t->right) q.push(t->right);
        }
    }
    return;
}