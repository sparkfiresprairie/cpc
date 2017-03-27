//
// Created by Xingyuan Wang on 3/27/17.
//

/*
    Given a singly linked list where elements are sorted in ascending order,
    convert it to a height balanced BST.
 */

#include "Tree.h"

TreeNode* help(ListNode* head, ListNode* tail) {
    ListNode* slow = head;
    ListNode* fast = head;
    if (head == tail) return nullptr;
    while (fast != tail && fast->next != tail) {
        fast = fast->next->next;
        slow = slow->next;
    }
    TreeNode* root = new TreeNode(slow->val);
    root->left = help(head, slow);
    root->right = help(slow->next, tail);
    return root;
}

TreeNode* sortedListToBST(ListNode* head) {
    return help(head, nullptr);
}

// time: O(nlogn)
// space: O(logn) if considering stack space


