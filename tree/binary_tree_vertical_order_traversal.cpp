//
// Created by Xingyuan Wang on 3/14/17.
//

/*
    Given a binary tree, return the vertical order traversal of its nodes' values.
    (ie, from top to bottom, column by column).

    If two nodes are in the same row and column, the order should be from left to
    right.

    Examples:

    Given binary tree [3,9,20,null,null,15,7],
       3
      /\
     /  \
     9  20
        /\
       /  \
      15   7
    return its vertical order traversal as:
    [
      [9],
      [3,15],
      [20],
      [7]
    ]
    Given binary tree [3,9,8,4,0,1,7],
         3
        /\
       /  \
       9   8
      /\  /\
     /  \/  \
     4  01   7
    return its vertical order traversal as:
    [
      [4],
      [9],
      [3,0,1],
      [8],
      [7]
    ]
    Given binary tree [3,9,8,4,0,1,7,null,null,null,2,5] (0's right child is 2 and 1's
    left child is 5),
         3
        /\
       /  \
       9   8
      /\  /\
     /  \/  \
     4  01   7
        /\
       /  \
       5   2
    return its vertical order traversal as:
    [
      [4],
      [9,5],
      [3,0,1],
      [8,2],
      [7]
    ]
 */

#include "Tree.h"

vector<vector<int>> verticalOrder(TreeNode* root) {
    map<int, vector<int>> mp;
    queue<pair<TreeNode*, int>> q;
    if (root) q.push({root, 0});
    while (!q.empty()) {
        auto e = q.front();
        q.pop();
        mp[e.second].push_back(e.first->val);
        if (e.first->left) q.push({e.first->left, e.second - 1});
        if (e.first->right) q.push({e.first->right, e.second + 1});
    }

    vector<vector<int>> ans;
    for (auto const& e : mp) {
        ans.push_back(e.second);
    }
    return ans;
}

// time: O(n)
// space: O(n)