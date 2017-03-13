//
// Created by Xingyuan Wang on 3/13/17.
//

/*
    You are given two non-empty linked lists representing two non-negative integers.
    The digits are stored in reverse order and each of their nodes contain a single
    digit. Add the two numbers and return it as a linked list.

    You may assume the two numbers do not contain any leading zero, except the number 0 itself.

    Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
    Output: 7 -> 0 -> 8
 */

#include "LinkedList.h"

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode dummy(0);
    ListNode* p = &dummy;
    int sum = 0, cin = 0;
    while (l1 || l2 || cin) {
        int num1 = l1 ? l1->val : 0;
        int num2 = l2 ? l2->val : 0;
        if (l1) l1 = l1->next;
        if (l2) l2 = l2->next;
        sum = num1 + num2 + cin;
        p->next = new ListNode(sum % 10);
        p = p->next;
        cin = sum / 10;
    }
    return dummy.next;
}
