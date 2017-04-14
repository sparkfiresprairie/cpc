//
// Created by Xingyuan Wang on 4/13/17.
//

/*
    Given a string, find the length of the longest substring without repeating characters.

    Examples:

    Given "abcabcbb", the answer is "abc", which the length is 3.

    Given "bbbbb", the answer is "b", with the length of 1.

    Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must
    be a substring, "pwke" is a subsequence and not a substring.
 */

#include "HashTable.h"

int lengthOfLongestSubstring(string s) {
    vector<int> mp(256, 0);
    int i = 0, j = 0, max_start = 0, max_len = 0;
    while (i < s.size()) {
        while (i < s.size() && mp[s[i]] == 0) {
            ++mp[s[i]];
            ++i;
        }
        if (i - j > max_len) {
            max_len = i - j;
            max_start = j;
        }
        --mp[s[j]];
        ++j;
    }
    return max_len;
}

// time: O(n)
// space: O(1)