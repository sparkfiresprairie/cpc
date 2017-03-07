//
// Created by Xingyuan Wang on 3/6/17.
//

/*
    Given two strings s and t, write a function to determine if t is an anagram of s.

    For example,
    s = "anagram", t = "nagaram", return true.
    s = "rat", t = "car", return false.

    Note:
    You may assume the string contains only lowercase alphabets.

    Follow up:
    What if the inputs contain unicode characters? How would you adapt your solution to such case?
 */

#include "HashTable.h"

bool isAnagram(string s, string t) {
    vector<int> mp(256, 0);
    int counter = 0;
    for (auto c : s) {
        ++mp[c];
        ++counter;
    }
    for (auto c : t) {
        if (mp[c] == 0) return false;
        --mp[c];
        --counter;
    }
    return counter == 0;
}

// time: O(n)
// space: O(1)