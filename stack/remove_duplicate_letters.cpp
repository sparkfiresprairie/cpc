//
// Created by Xingyuan Wang on 3/14/17.
//

/*
    Given a string which contains only lowercase letters, remove duplicate letters
    so that every letter appear once and only once. You must make sure your result
    is the smallest in lexicographical order among all possible results.

    Example:
    Given "bcabc"
    Return "abc"

    Given "cbacdcbc"
    Return "acdb"
 */

#include "Stack.h"

string removeDuplicateLetters(string s) {
    vector<int> mp(256, 0);
    vector<bool> in_output(256, false);
    for (char c : s) {
        ++mp[c];
    }
    string output;
    for (char c : s) {
        --mp[c];
        if (in_output[c]) continue;
        while (!output.empty() && c < output.back() && mp[output.back()] > 0) {
            in_output[output.back()] = false;
            output.pop_back();
        }
        output += c;
        in_output[c] = true;
    }
    return output;
}

// time: O(n)
// space: O(1) or O(n) if output is considered

