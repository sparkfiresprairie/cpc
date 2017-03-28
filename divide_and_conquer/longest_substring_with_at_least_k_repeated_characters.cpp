//
// Created by Xingyuan Wang on 3/27/17.
//

/*
    Find the length of the longest substring T of a given string (consists of lowercase
    letters only) such that every character in T appears no less than k times.

    Example 1:

    Input:
    s = "aaabb", k = 3

    Output:
    3

    The longest substring is "aaa", as 'a' is repeated 3 times.
    Example 2:

    Input:
    s = "ababbc", k = 2

    Output:
    5

    The longest substring is "ababb", as 'a' is repeated 2 times and 'b' is repeated 3
    times.
 */

#include "DivideAndConquer.h"

int help(string const& s, int b, int e, int k) {
    if (e - b == 0 || k > e - b) return 0;
    if (k == 0) return e - b;
    vector<int> mp(256, 0);
    for (int i = b; i < e; ++i) {
        ++mp[s[i]];
    }
    int idx = b;
    while (idx < e && mp[s[idx]] >= k) ++idx;
    if (idx == e) return e - b;
    int left = help(s, b, idx, k);
    int right = help(s, idx + 1, e, k);
    return max(left, right);
}

int longestSubstring(string s, int k) {
    return help(s, 0, s.size(), k);
}


// time: worst case O(n^2)
// space: worse case O(n) considering stack space
