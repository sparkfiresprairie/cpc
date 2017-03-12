//
// Created by Xingyuan Wang on 3/12/17.
//

/*
    Given a string s and a non-empty string p, find all the start indices of p's
    anagrams in s.

    Strings consists of lowercase English letters only and the length of both
    strings s and p will not be larger than 20,100.

    The order of output does not matter.

    Example 1:

    Input:
    s: "cbaebabacd" p: "abc"

    Output:
    [0, 6]

    Explanation:
    The substring with start index = 0 is "cba", which is an anagram of "abc".
    The substring with start index = 6 is "bac", which is an anagram of "abc".
    Example 2:

    Input:
    s: "abab" p: "ab"

    Output:
    [0, 1, 2]

    Explanation:
    The substring with start index = 0 is "ab", which is an anagram of "ab".
    The substring with start index = 1 is "ba", which is an anagram of "ab".
    The substring with start index = 2 is "ab", which is an anagram of "ab".
 */

#include "HashTable.h"

vector<int> findAnagrams(string s, string p) {
    vector<int> indices;
    if (s.empty() || p.empty()) return indices;
    vector<int> mp(256, 0);
    for (auto c : p) {
        ++mp[c];
    }
    int left = 0, right = 0, counter = p.size();
    while (right < s.size()) {
        if (mp[s[right]] > 0) {
            --counter;
        }
        --mp[s[right]];
        ++right;
        if (counter == 0) {
            indices.push_back(left);
        }
        if (right - left == p.size()) {
            if (mp[s[left]] >= 0) {
                ++counter;
            }
            ++mp[s[left]];
            ++left;
        }
    }
    return indices;
}

// time: O(s.size())
// space: O(1)

