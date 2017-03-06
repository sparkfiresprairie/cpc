//
// Created by Xingyuan Wang on 3/5/17.
//

/*
    Given a singly linked list, determine if it is a palindrome.

    Follow up:
    Could you do it in O(n) time and O(1) space?
 */

#include "LinkedList.h"

ListNode* reverseLinkedList(ListNode* head) {
    ListNode dummy(0);
    ListNode* pre = &dummy;
    pre->next = head;
    ListNode* cur = pre->next;
    ListNode* next = nullptr;
    while (cur && cur->next) {
        next = cur->next;
        cur->next = next->next;
        next->next = pre->next;
        pre->next = next;
    }
    return dummy.next;
}

bool isPalindrome(ListNode* head) {
    if (!head) return true;
    ListNode* fast = head;
    ListNode* slow = head;
    while (fast->next && fast->next->next) {
        fast = fast->next->next;
        slow = slow->next;
    }
    ListNode* l1 = head;
    ListNode* l2 = reverseLinkedList(slow->next);
    slow->next = nullptr;
    while (l1 && l2) {
        if (l1->val != l2->val) return false;
        l1 = l1->next;
        l2 = l2->next;
    }
    return true;
}

// time: O(n)
// space: O(1)


