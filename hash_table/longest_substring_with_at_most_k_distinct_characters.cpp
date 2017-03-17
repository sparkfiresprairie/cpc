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
    unordered_map<char, int> ht;
    if (k == 0) return 0;
    int i = 0, j = 0;
    int max_len = 0;
    while (i < s.size()) {
        while (i < s.size() && (ht.size() < k || ht.size() == k && ht.find(s[i]) != ht.end())) {
            ++ht[s[i]];
            ++i;
            continue;
        }
        max_len = max(max_len, i - j);
        --ht[s[j]];
        if (ht[s[j]] == 0) ht.erase(s[j]);
        ++j;
    }
    return max_len;
}