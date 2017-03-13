//
// Created by Xingyuan Wang on 3/12/17.
//

/*
    Given a string, find the first non-repeating character in it and return
    it's index. If it doesn't exist, return -1.

    Examples:

    s = "leetcode"
    return 0.

    s = "loveleetcode",
    return 2.
    Note: You may assume the string contain only lowercase letters.
 */

#include "HashTable.h"

int firstUniqChar(string s) {
    vector<int> mp(26, 0);
    for (auto c : s) {
        mp[c - 'a'] += 1;
    }
    for (int i = 0; i < s.size(); ++i) {
        if (mp[s[i] - 'a'] == 1) return i;
    }
    return -1;
}

// time: O(n)
// space: O(1)