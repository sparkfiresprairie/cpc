//
// Created by Xingyuan Wang on 3/17/17.
//

/*
    Given an input string, reverse the string word by word. A word is defined
    as a sequence of non-space characters.

    The input string does not contain leading or trailing spaces and the words
    are always separated by a single space.

    For example,
    Given s = "the sky is blue",
    return "blue is sky the".

    Could you do it in-place without allocating extra space?
 */

#include "String.h"

void reverseWords(string &s) {
    reverse(s.begin(), s.end());
    for (int i = 0; i < s.size(); ++i) {
        int j = i;
        while (i < s.size() && s[i] != ' ') ++i;
        reverse(s.begin() + j, s.begin() + i);
    }
}