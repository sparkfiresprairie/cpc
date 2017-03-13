//
// Created by Xingyuan Wang on 3/13/17.
//

/*
    Given a linked list, determine if it has a cycle in it.

    Follow up:
    Can you solve it without using extra space?
 */

#include "LinkedList.h"

bool hasCycle(ListNode *head) {
    if (!head) return false;
    ListNode* fast = head;
    ListNode* slow = head;
    while (fast->next && fast->next->next) {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow) return true;
    }
    return false;
}

// time: O(n)
// space: O(1)