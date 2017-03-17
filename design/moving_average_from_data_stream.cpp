//
// Created by Xingyuan Wang on 3/17/17.
//

/*
    Given a stream of integers and a window size, calculate the moving average
    of all integers in the sliding window.

    For example,
    MovingAverage m = new MovingAverage(3);
    m.next(1) = 1
    m.next(10) = (1 + 10) / 2
    m.next(3) = (1 + 10 + 3) / 3
    m.next(5) = (10 + 3 + 5) / 3
 */

#include "Design.h"

class MovingAverage {
    int n;
    double average;
    queue<int> q;
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        n = size;
        average = 0;
    }

    double next(int val) {
        if (n == 1) return val;
        if (q.size() == n) {
            average = (average * n - q.front()) / (n - 1);
            q.pop();
        }
        average = (average * q.size() + val) / (q.size() + 1);
        q.push(val);
        return average;
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */