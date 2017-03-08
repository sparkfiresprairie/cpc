//
// Created by Xingyuan Wang on 3/7/17.
//

/*
    Given a binary tree, return all root-to-leaf paths.

    For example, given the following binary tree:

       1
     /   \
    2     3
     \
      5
    All root-to-leaf paths are:

    ["1->2->5", "1->3"]

 */

#include "Tree.h"

void help(TreeNode* root, string path, vector<string>& paths) {
    if (!root) return;
    path.append(to_string(root->val));
    if (!root->left && !root->right) {
        paths.push_back(path);
        return;
    }
    path.append("->");
    help(root->left, path, paths);
    help(root->right, path, paths);
}

vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> paths;
    string path;
    help(root, path, paths);
    return paths;
}

//void help(TreeNode* root, string& path, vector<string>& paths) {
//    if (!root) return;
//    int sz = path.size();
//    path.append(to_string(root->val));
//    if (!root->left && !root->right) {
//        paths.push_back(path);
//    }
//    path.append("->");
//    if (root->left) help(root->left, path, paths);
//    if (root->right) help(root->right, path, paths);
//    path.erase(path.begin() + sz, path.end());
//}
//
//
//vector<string> binaryTreePaths(TreeNode* root) {
//    vector<string> paths;
//    string path;
//    help(root, path, paths);
//    return paths;
//}




