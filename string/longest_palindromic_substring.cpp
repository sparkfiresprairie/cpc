//
// Created by Xingyuan Wang on 3/12/17.
//

/*
    Given a string s, find the longest palindromic substring in s. You may
    assume that the maximum length of s is 1000.

    Example:

    Input: "babad"

    Output: "bab"

    Note: "aba" is also a valid answer.
    Example:

    Input: "cbbd"

    Output: "bb"
 */


#include "String.h"

string longestPalindrome(string s) {
    int max_start = 0, max_len = INT_MIN;
    for (int i = 0; i < s.size(); ++i) {
        int j = i;
        while (i + 1 < s.size() && s[i + 1] == s[i]) ++i;
        int k = i;
        while (j - 1 >= 0 && i + 1 < s.size() && s[j - 1] == s[i + 1]) {
            --j;
            ++i;
        }
        if (i - j + 1 > max_len) {
            max_len = i - j + 1;
            max_start = j;
        }
        i = k;
    }
    return s.substr(max_start, max_len);
}

// time: worst case O(n^2)
// space: O(1)