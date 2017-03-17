//
// Created by Xingyuan Wang on 3/17/17.
//

/*
    Given a non-negative integer represented as non-empty a singly linked list of digits,
    plus one to the integer.

    You may assume the integer do not contain any leading zero, except the number 0 itself.

    The digits are stored such that the most significant digit is at the head of the list.

    Example:
    Input:
    1->2->3

    Output:
    1->2->4
 */

#include "LinkedList.h"

ListNode* plusOne(ListNode* head) {
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* p = dummy;
    ListNode* q = dummy;

    while (p->next) {
        p = p->next;
        if (p->val != 9) q = p;
    }

    if (p->val != 9) {
        p->val += 1;
    } else {
        q->val += 1;
        q = q->next;
        while (q) {
            q->val = 0;
            q = q->next;
        }
    }
    if (dummy->val == 0) {
        ListNode* t = dummy->next;
        delete dummy;
        return t;
    }
    return dummy;
}