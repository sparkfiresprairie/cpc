//
// Created by Xingyuan Wang on 3/28/17.
//

#include "Design.h"

class MinStack {
private:
    stack<int> s1;
    stack<int> s2;
public:
    /** initialize your data structure here. */
    MinStack() {}

    void push(int x) {
        s1.push(x);
        if (!s2.empty()) x = min(x, s2.top());
        s2.push(x);
    }

    void pop() {
        s1.pop();
        s2.pop();
    }

    int top() {
        return s1.top();
    }

    int getMin() {
        return s2.top();
    }

    bool empty() {
        return s1.empty() && s2.empty();
    }
};

class MinQueue {
private:
    MinStack s1;
    MinStack s2;
    void assertS2NotEmmpty(void) {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
    }
public:
    void push(int x) {
        s1.push(x);
    }

    int pop() {
        assertS2NotEmmpty();
        int t = s2.top();
        s2.pop();
        return t;
    }

    int front() {
        assertS2NotEmmpty();
        return s2.top();
    }

    int getMin() {
        assertS2NotEmmpty();
        return s2.getMin();
    }

    bool empty() {
        return s1.empty() && s2.empty();
    }
};