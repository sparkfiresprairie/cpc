//
// Created by Xingyuan Wang on 3/28/17.
//

/*
    Reverse a linked list from position m to n. Do it in-place and
    in one-pass.

    For example:
    Given 1->2->3->4->5->NULL, m = 2 and n = 4,

    return 1->4->3->2->5->NULL.

    Note:
    Given m, n satisfy the following condition:
    1 ≤ m ≤ n ≤ length of list.
 */

#include "LinkedList.h"

ListNode* reverseBetween(ListNode* head, int m, int n) {
    ListNode dummy(0);
    ListNode* pre = &dummy;
    pre->next = head;
    for (int i = 1; i < m; ++i) {
        pre = pre->next;
    }
    ListNode* cur = pre->next;
    ListNode* next = cur->next;
    for (int i = 0; i < n - m; ++i) {
        cur->next = next->next;
        next->next = pre->next;
        pre->next = next;
        next = cur->next;
    }
    return dummy.next;
}

// time: O(n)
// space: O(1)