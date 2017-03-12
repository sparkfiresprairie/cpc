//
// Created by Xingyuan Wang on 3/11/17.
//

/*
    Median is the middle value in an ordered integer list. If the size of the list is even,
    there is no middle value. So the median is the mean of the two middle value.

    Examples:
    [2,3,4] , the median is 3

    [2,3], the median is (2 + 3) / 2 = 2.5

    Design a data structure that supports the following two operations:

    void addNum(int num) - Add a integer number from the data stream to the data structure.
    double findMedian() - Return the median of all elements so far.
    For example:

    addNum(1)
    addNum(2)
    findMedian() -> 1.5
    addNum(3)
    findMedian() -> 2
 */

#include "Heap.h"

class MedianFinder {
    priority_queue<int> small, large;
public:
    // Adds a number into the data structure.
    void addNum(int num) {
        small.push(num);
        large.push(-small.top());
        small.pop();
        if (small.size() < large.size()) {
            small.push(-large.top());
            large.pop();
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        if (small.size() > large.size()) return small.top();
        else return (small.top() - large.top()) / 2.0;
    }
};

// time: add - O(nlogn) find - O(1)
// space: O(n)