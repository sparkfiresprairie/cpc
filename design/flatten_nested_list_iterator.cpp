//
// Created by Xingyuan Wang on 3/13/17.
//

/*
    Given a nested list of integers, implement an iterator to flatten it.

    Each element is either an integer, or a list -- whose elements may also be
    integers or other lists.

    Example 1:
    Given the list [[1,1],2,[1,1]],

    By calling next repeatedly until hasNext returns false, the order of elements
    returned by next should be: [1,1,2,1,1].

    Example 2:
    Given the list [1,[4,[6]]],

    By calling next repeatedly until hasNext returns false, the order of elements
    returned by next should be: [1,4,6].
 */


// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger {
public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

#include "Design.h"

class NestedIterator {
    using IT = vector<NestedInteger>::iterator;
    stack<IT> begins;
    stack<IT> ends;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        begins.push(nestedList.begin());
        ends.push(nestedList.end());
    }

    int next() {
        return (begins.top()++)->getInteger();
    }

    bool hasNext() {
        while (!begins.empty()) {
            if (begins.top() == ends.top()) {
                begins.pop();
                ends.pop();
            } else {
                auto b = begins.top();
                if (b->isInteger()) return true;
                else {
                    ++begins.top();
                    begins.push((b->getList()).begin());
                    ends.push((b->getList()).end());
                }
            }
        }
        return false;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */

// time: amortized O(1)
// space: O(n)

vector<int> flattenNestedList(vector<NestedInteger> const& nestedList) {
    vector<int> list;
    for (auto const& ni : nestedList) {
        if (ni.isInteger()) {
            list.push_back(ni.getInteger());
        } else {
            vector<int> l = flattenNestedList(ni.getList());
            for (auto i : l) {
                list.push_back(i);
            }
        }
    }
    return list;
}