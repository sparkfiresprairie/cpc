//
// Created by Xingyuan Wang on 3/5/17.
//

/*
    Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

    Note:
    You may assume k is always valid, 1 ≤ k ≤ BST's total elements.

    Follow up:
    What if the BST is modified (insert/delete operations) often and you need to find the kth smallest
    frequently? How would you optimize the kthSmallest routine?

    Hint:

    Try to utilize the property of a BST.
    What if you could modify the BST node's structure?
    The optimal runtime complexity is O(height of BST).

 */

#include "Tree.h"

int kthSmallest(TreeNode* root, int k) {
    stack<TreeNode*> stk;
    TreeNode* t = root;
    while (t || !stk.empty()) {
        while (t) {
            stk.push(t);
            t = t->left;
        }
        t = stk.top();
        stk.pop();
        if (--k == 0) return t->val;
        t = t->right;
    }
}

// time: O(n)
// space: O(logn)
