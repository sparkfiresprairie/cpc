//
// Created by Xingyuan Wang on 3/20/17.
//

/*
    Write a function that takes a string as input and returns the string reversed.

    Example:
    Given s = "hello", return "olleh".
 */

#include "String.h"

string reverseString(string s) {
    int i = 0, j = s.size() - 1;
    while (i < j) {
        swap(s[i++], s[j--]);
    }
    return s;
}

// time: O(n)
// space: O(1)