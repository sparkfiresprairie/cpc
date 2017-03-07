//
// Created by Xingyuan Wang on 3/6/17.
//

/*
    Implement an iterator to flatten a 2d vector.

    For example,
    Given 2d vector =

    [
      [1,2],
      [3],
      [4,5,6]
    ]
    By calling next repeatedly until hasNext returns false, the order of elements returned
    by next should be: [1,2,3,4,5,6].

    Hint:

    How many variables do you need to keep track?
    Two variables is all you need. Try with x and y.
    Beware of empty rows. It could be the first few rows.
    To write correct code, think about the invariant to maintain. What is it?
    The invariant is x and y must always point to a valid point in the 2d vector. Should you
    maintain your invariant ahead of time or right when you need it?
    Not sure? Think about how you would implement hasNext(). Which is more complex?
    Common logic in two different places should be refactored into a common method.
    Follow up:
    As an added challenge, try to code it using only iterators in C++ or iterators in Java.
 */

#include "Design.h"

class Vector2D {
    vector<vector<int>>::iterator it, ite;
    int j = 0;
public:
    Vector2D(vector<vector<int>>& vec2d) {
        it = vec2d.begin();
        ite = vec2d.end();
    }

    int next() {
        hasNext();
        return (*it)[j++];
    }

    bool hasNext() {
        while (it != ite && j == (*it).size()) {
            ++it;
            j = 0;
        }
        return it != ite;
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */