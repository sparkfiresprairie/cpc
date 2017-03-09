//
// Created by Xingyuan Wang on 3/8/17.
//

/*
    Given two 1d vectors, implement an iterator to return their elements alternately.

    For example, given two 1d vectors:

    v1 = [1, 2]
    v2 = [3, 4, 5, 6]
    By calling next repeatedly until hasNext returns false, the order of elements returned by next
    should be: [1, 3, 2, 4, 5, 6].

    Follow up: What if you are given k 1d vectors? How well can your code be extended to such cases?

    Clarification for the follow up question - Update (2015-09-18):
    The "Zigzag" order is not clearly defined and is ambiguous for k > 2 cases. If "Zigzag" does not
    look right to you, replace "Zigzag" with "Cyclic". For example, given the following input:

    [1,2,3]
    [4,5,6,7]
    [8,9]
    It should return [1,4,8,2,5,9,3,6,7].
 */

#include "Design.h"

class ZigzagIterator {
    using IT = vector<int>::iterator;
    queue<pair<IT, IT>> q;
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        if (!v1.empty()) q.push({v1.begin(), v1.end()});
        if (!v2.empty()) q.push({v2.begin(), v2.end()});
    }

    int next() {
        auto b = q.front().first;
        auto e = q.front().second;
        q.pop();
        int t = *b++;
        if (b != e) q.push({b, e});
        return t;
    }

    bool hasNext() {
        return !q.empty();
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */

// time: O(kn) (n is the average size of each vector)
// space: O(k)