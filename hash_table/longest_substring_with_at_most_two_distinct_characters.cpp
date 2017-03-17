//
// Created by Xingyuan Wang on 3/17/17.
//

/*
    Given a string, find the length of the longest substring T that contains at
    most 2 distinct characters.

    For example, Given s = “eceba”,

    T is "ece" which its length is 3.
 */

#include "HashTable.h"

int lengthOfLongestSubstringTwoDistinct(string s) {
    vector<int> m(256, 0);
    int counter = 2;
    int max_len = 0;
    int i = 0, j = 0;
    while (i < s.size()) {
        while (i < s.size() && !(counter == 0 && m[s[i]] == 0)) {
            if (m[s[i]] == 0) --counter;
            ++m[s[i]];
            ++i;
        }
        max_len = max(max_len, i - j);
        --m[s[j]];
        if (m[s[j]] == 0) ++counter;
        ++j;
    }
    return max_len;
}