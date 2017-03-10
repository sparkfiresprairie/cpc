//
// Created by Xingyuan Wang on 3/10/17.
//

/*
    Serialization is the process of converting a data structure or object into a sequence of
    bits so that it can be stored in a file or memory buffer, or transmitted across a network
    connection link to be reconstructed later in the same or another computer environment.

    Design an algorithm to serialize and deserialize a binary tree. There is no restriction
    on how your serialization/deserialization algorithm should work. You just need to ensure
    that a binary tree can be serialized to a string and this string can be deserialized to
    the original tree structure.

    For example, you may serialize the following tree

        1
       / \
      2   3
         / \
        4   5
    as "[1,2,3,null,null,4,5]", just the same as how LeetCode OJ serializes a binary tree.
    You do not necessarily need to follow this format, so please be creative and come up
    with different approaches yourself.
    Note: Do not use class member/global/static variables to store states. Your serialize
    and deserialize algorithms should be stateless.
 */

#include "Tree.h"

class Codec {
public:

    struct TreeNode2 {
        int val;
        bool has_left;
        bool has_right;
        TreeNode2(int val) : val(val), has_left(false), has_right(false) {}
    };

    vector<TreeNode2> serialize2(TreeNode* root) {
        vector<TreeNode2> ans;
        queue<TreeNode*> q;
        if (root) q.push(root);
        while (!q.empty()) {
            TreeNode* t = q.front();
            q.pop();
            TreeNode2 node(t->val);
            if (t->left) {
                q.push(t->left);
                node.has_left = true;
            }
            if (t->right) {
                q.push(t->right);
                node.has_right = true;
            }
            ans.push_back(node);
        }
        return ans;
    }

    struct TreeNodeWrapper {
        TreeNode* p;
        bool need_left;
        bool need_right;
        TreeNodeWrapper(TreeNode* p, bool l, bool r) : p(p), need_left(l), need_right(r) {}
    };

    TreeNode* deserialize2(vector<TreeNode2> const& tree) {
        TreeNode dummy(0);
        TreeNodeWrapper dummy_wrapper(&dummy, false, true);
        queue<TreeNodeWrapper> q;
        q.push(dummy_wrapper);
        for (int i = 0; i < tree.size(); ++i) {
            TreeNodeWrapper node(new TreeNode(tree[i].val), tree[i].has_left, tree[i].has_right);
            if (node.need_left || node.need_right) q.push(node);
            auto& t = q.front();
            if (t.need_left) {
                t.p->left = node.p;
                t.need_left = false;
            } else {
                t.p->right = node.p;
                t.need_right = false;
            }
            if (!t.need_left && !t.need_right) q.pop();
        }
        return dummy.right;
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        TreeNode* r = deserialize2(serialize2(root));
        string s;
        queue<TreeNode*> q;
        q.push(r);
        while (!q.empty()) {
            TreeNode* t = q.front();
            q.pop();
            if (t == nullptr) s += "#,";
            else {
                s += to_string(t->val) + ",";
                q.push(t->left);
                q.push(t->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode dummy(0);
        bool is_left = false;
        queue<TreeNode*> q;
        q.push(&dummy);
        for (int i = 0; i < data.size(); ++i) {
            int j = i;
            while (i < data.size() && data[i] != ',') ++i;
            string t = data.substr(j, i - j);
            TreeNode* next = nullptr;
            if (t != "#") {
                next = new TreeNode(stoi(t));
                q.push(next);
            }
            if (is_left) {
                q.front()->left = next;
            } else {
                q.front()->right = next;
                q.pop();
            }
            is_left = !is_left;
        }
        return dummy.right;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));