//
// Created by Xingyuan Wang on 3/13/17.
//

/*
    Given an array of strings, group anagrams together.

    For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"],
    Return:

    [
      ["ate", "eat","tea"],
      ["nat","tan"],
      ["bat"]
    ]
    Note: All inputs will be in lower-case.
 */

#include "HashTable.h"

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> mp;
    for (string const& s : strs) {
        string t = s;
        sort(t.begin(), t.end());
        mp[t].push_back(s);
    }
    vector<vector<string>> groups;
    for (auto const& m : mp) {
        groups.push_back(m.second);
    }
    return groups;
}

// time: O(nlogl)
// space: O(n)

