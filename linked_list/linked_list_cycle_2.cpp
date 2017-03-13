//
// Created by Xingyuan Wang on 3/13/17.
//

/*
    Given a linked list, return the node where the cycle begins. If there is no
    cycle, return null.

    Note: Do not modify the linked list.

    Follow up:
    Can you solve it without using extra space?
 */

#include "LinkedList.h"

/* my solution is like this: using two pointers, one of them one step at a time.
     * another pointer each take two steps. Suppose the first meet at step k,the length
     * of the Cycle is r. so..2k-k=nr,k=nr
     * Now, the distance between the start node of list and the start node of cycle is s.
     * the distance between the start of list and the first meeting node is k(the pointer
     * which wake one step at a time waked k steps).the distance between the start node
     * of cycle and the first meeting node is m, so...s=k-m,
     * s=nr-m=(n-1)r+(r-m),here we takes n = 1..so, using one pointer start from the start
     * node of list, another pointer start from the first meeting node, all of them wake
     * one step at a time, the first time they meeting each other is the start of the cycle.
     */
ListNode *detectCycle(ListNode *head) {
    if (!head) return nullptr;
    ListNode* fast = head;
    ListNode* slow = head;
    bool hasCycle = false;
    while (fast->next && fast->next->next) {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow) {
            hasCycle = true;
            break;
        }
    }
    if (!hasCycle) return nullptr;
    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}

// time: O(n)
// space: O(1)