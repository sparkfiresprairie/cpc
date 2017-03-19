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

int maxDiff(vector<int> const& nums) {
    if (nums.empty()) return 0;
    int min_num= nums[0];
    int max_diff = 0;
    for (int i = 1; i < nums.size(); ++i) {
        max_diff = max(max_diff, nums[i] - min_num);

    }
}