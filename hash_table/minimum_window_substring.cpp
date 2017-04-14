//
// Created by Xingyuan Wang on 4/13/17.
//

/*
    Given a string S and a string T, find the minimum window in S which will contain
    all the characters in T in complexity O(n).

    For example,
    S = "ADOBECODEBANC"
    T = "ABC"
    Minimum window is "BANC".

    Note:
    If there is no such window in S that covers all characters in T, return the empty
    string "".

    If there are multiple such windows, you are guaranteed that there will always be
    only one unique minimum window in S.
 */

#include "HashTable.h"

string minWindow(string s, string t) {
    vector<int> mp(256, 0);
    for (auto c : t) {
        ++mp[c];
    }
    int counter = t.size();
    int i = 0, j = 0;
    int min_start = 0, min_len = INT_MAX;
    while (i < s.size()) {
        if (mp[s[i]] > 0) --counter;
        --mp[s[i]];
        while (counter == 0) {
            if (i - j + 1 < min_len) {
                min_len = i - j + 1;
                min_start = j;
            }
            ++mp[s[j]];
            if (mp[s[j]] > 0) ++counter;
            ++j;
        }
        ++i;
    }
    if (min_len == INT_MAX) return "";
    else return s.substr(min_start, min_len);
}

// time: O(n)
// space: O(1)