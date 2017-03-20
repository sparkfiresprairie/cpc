//
// Created by Xingyuan Wang on 3/17/17.
//

/*
    Given a binary tree, find the largest subtree which is a Binary Search Tree (BST),
    where largest means subtree with largest number of nodes in it.

    Note:
    A subtree must include all of its descendants.
    Here's an example:
        10
        / \
       5  15
      / \   \
     1   8   7
    The Largest BST Subtree in this case is the highlighted one.
    The return value is the subtree's size, which is 3.
    Hint:

    You can recursively use algorithm similar to 98. Validate Binary Search Tree at each
    node of the tree, which will result in O(nlogn) time complexity.
    Follow up:
    Can you figure out ways to solve it with O(n) time complexity?
 */

#include "Tree.h"

// here the help function can be considered as having four return values
// 1. if root is BST
// 2. root's size
// 3. min value of root;
// 4. max value of root;
bool help(TreeNode* root, int& res, int& mini, int& maxi) {
    if (!root) return true;

    int left_size = 0, right_size = 0;
    int left_mini, left_maxi, right_mini, right_maxi;
    bool leftBST = help(root->left, left_size, left_mini, left_maxi);
    bool rightBST = help(root->right, right_size, right_mini, right_maxi);
    if (leftBST && rightBST) {
        if ( (!root->left || root->val >= left_maxi) && (!root->right || root->val <= right_mini) ) {
            res = left_size + right_size + 1;
            mini = root->left ? left_mini : root->val;
            maxi = root->right ? right_maxi : root->val;
            return true;
        }
    }
    // The tree rooted at this node is not a binary search tree,
    // so take the maximum size of the BST in the left or right
    // subtrees
    res = max(left_size, right_size);
    return false;
}

int largestBSTSubtree(TreeNode* root) {
    int res = 0;
    int mini, maxi;
    help(root, res, mini, maxi);
    return res;
}

// time: O(n)
// space: O(logn)

