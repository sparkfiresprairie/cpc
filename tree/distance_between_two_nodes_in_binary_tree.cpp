//
// Created by Xingyuan Wang on 3/13/17.
//

/*
    Find the distance between two keys in a binary tree, no parent pointers are given.
    Distance between two nodes is the minimum number of edges to be traversed to reach
    one node from other.
 */

#include "Tree.h"

TreeNode* lca(TreeNode* root, TreeNode* node1, TreeNode* node2) {
    if (!root) return nullptr;
    if (root == node1) return node1;
    else if (root == node2) return node2;
    TreeNode* left = lca(root->left, node1, node2);
    TreeNode* right = lca(root->right, node1, node2);
    if (left && right) return root;
    else if (left) return left;
    else if (right) return right;
    else return nullptr;
}

int getDepth(TreeNode* root, TreeNode* node) {
    if (!root) return -1;
    if (root == node) return 0;
    int left = getDepth(root->left, node);
    int right = getDepth(root->right, node);
    if (left == -1 && right == -1) return -1;
    else {
        if (left != -1) {
            return left + 1;
        } else {
            return right + 1;
        }
    }
}

int getDistance(TreeNode* root, TreeNode* node1, TreeNode* node2) {
    if (!root || !node1 || !node2) return -1;
    TreeNode* ancestor = lca(root, node1, node2);
    int depth1 = getDepth(root, ancestor);
    int depth2 = getDepth(root, node1);
    int depth3 = getDepth(root, node2);
    return depth3 + depth2 - 2 * depth1;
}
