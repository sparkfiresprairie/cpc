//
// Created by Xingyuan Wang on 3/17/17.
//

/*
    Given a string, find the length of the longest substring T that contains at most
    k distinct characters.

    For example, Given s = “eceba” and k = 2,

    T is "ece" which its length is 3.
 */

#include "HashTable.h"

int lengthOfLongestSubstringKDistinct(string s, int k) {
    vector<int> mp(256, 0);
    if (k == 0) return 0;
    int i = 0, j = 0;
    int max_len = 0;
    while (i < s.size()) {
        while (i < s.size() && (mp[s[i]] > 0 || k > 0)) {
            if (mp[s[i]] == 0) --k;
            ++mp[s[i]];
            ++i;
        }
        max_len = max(max_len, i - j);
        --mp[s[j]];
        if (mp[s[j]] == 0) ++k;
        ++j;
    }
    return max_len;
}

// time: O(n)
// space: O(1)