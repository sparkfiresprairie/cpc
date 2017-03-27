//
// Created by Xingyuan Wang on 3/27/17.
//

/*
    Given an array where elements are sorted in ascending order, convert it to a
    height balanced BST.
 */

#include "Tree.h"

TreeNode* help(vector<int> const& nums, int low, int high) {
    if (low > high) return nullptr;
    int mid = low + (high - low) / 2;
    TreeNode* root = new TreeNode(nums[mid]);
    root->left = help(nums, low, mid - 1);
    root->right = help(nums, mid + 1, high);
    return root;
}

TreeNode* sortedArrayToBST(vector<int>& nums) {
    int n = nums.size();
    return help(nums, 0, n - 1);
}

// time: O(n)
// space: O(logn) considering stack

