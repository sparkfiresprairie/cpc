//
// Created by Xingyuan Wang on 2/27/17.
//

/*
    Given a complete binary tree, count the number of nodes.

    Definition of a complete binary tree from Wikipedia:
    In a complete binary tree every level, except possibly the last, is completely
    filled, and all nodes in the last level are as far left as possible. It can
    have between 1 and 2h nodes inclusive at the last level h.
 */

#include "Tree.h"

int countNodes(TreeNode* root) {
    if (!root) return 0;
    int hl = 0;
    int hr = 0;
    TreeNode* l = root;
    TreeNode* r = root;
    while (l) {
        ++hl;
        l = l->left;
    }
    while (r) {
        ++hr;
        r = r->right;
    }
    if (hl == hr) return pow(2, hl) - 1;
    return 1 + countNodes(root->left) + countNodes(root->right);
}
