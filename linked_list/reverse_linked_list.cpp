//
// Created by Xingyuan Wang on 3/12/17.
//

/*
    Reverse a singly linked list.
 */

#include "LinkedList.h"

ListNode* reverseList(ListNode* head) {
    ListNode dummy(0);
    dummy.next = head;
    ListNode* prev = &dummy;
    ListNode* cur = prev->next;
    ListNode* next;
    while (cur) {
        next = cur->next;
        if (!next) break;
        cur->next = next->next;
        next->next = prev->next;
        prev->next = next;
    }
    return dummy.next;
}

// time: O(n)
// space: O(1)