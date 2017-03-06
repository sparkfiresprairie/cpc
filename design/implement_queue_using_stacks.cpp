//
// Created by Xingyuan Wang on 3/5/17.
//

/*
    Implement the following operations of a queue using stacks.

    push(x) -- Push element x to the back of queue.
    pop() -- Removes the element from in front of queue.
    peek() -- Get the front element.
    empty() -- Return whether the queue is empty.
    Notes:
    You must use only standard operations of a stack -- which means only
    push to top, peek/pop from top, size, and is empty operations are valid.
    Depending on your language, stack may not be supported natively. You may
    simulate a stack by using a list or deque (double-ended queue), as long
    as you use only standard operations of a stack. You may assume that all
    operations are valid (for example, no pop or peek operations will be
    called on an empty queue).
 */

#include "Design.h"

class MyQueue {
    stack<int> stk1;
    stack<int> stk2;
    void assertStk2NotEmpty(void) {
        if (stk2.empty()) {
            while (!stk1.empty()) {
                stk2.push(stk1.top());
                stk1.pop();
            }
        }
    }
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }

    /** Push element x to the back of queue. */
    void push(int x) {
        stk1.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        assertStk2NotEmpty();
        int t = stk2.top();
        stk2.pop();
        return t;
    }

    /** Get the front element. */
    int peek() {
        assertStk2NotEmpty();
        return stk2.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return stk1.empty() && stk2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */

// time: push, empty-O(1), pop, peek-O(n)(worst), O(1)(amortised)
// space: O(n)