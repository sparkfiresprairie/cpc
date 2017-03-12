//
// Created by Xingyuan Wang on 3/12/17.
//

/*
    A linked list is given such that each node contains an additional random
    pointer which could point to any node in the list or null.

    Return a deep copy of the list.
 */

#include "LinkedList.h"

RandomListNode *copyRandomList(RandomListNode *head) {
    RandomListNode dummy(0);
    RandomListNode* p = &dummy;
    p->next = head;
    while (p->next) {
        p = p->next;
        RandomListNode* q = new RandomListNode(p->label);
        q->next = p->next;
        p->next = q;
        p = p->next;
    }
    p = &dummy;
    while (p->next) {
        p = p->next;
        RandomListNode* q = p->next;
        if (p->random) q->random = p->random->next;
        p = q;
    }
    p = &dummy;
    while (p->next) {
        RandomListNode* s = p->next;
        RandomListNode* t = p->next->next;
        p->next = t;
        s->next = t->next;
        p = t;
    }
    return dummy.next;
}

