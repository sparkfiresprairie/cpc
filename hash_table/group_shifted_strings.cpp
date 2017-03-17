//
// Created by Xingyuan Wang on 3/17/17.
//

/*
    Given a string, we can "shift" each of its letter to its successive letter,
    for example: "abc" -> "bcd". We can keep "shifting" which forms the sequence:

    "abc" -> "bcd" -> ... -> "xyz"
    Given a list of strings which contains only lowercase alphabets, group all
    strings that belong to the same shifting sequence.

    For example, given: ["abc", "bcd", "acef", "xyz", "az", "ba", "a", "z"],
    A solution is:

    [
      ["abc","bcd","xyz"],
      ["az","ba"],
      ["acef"],
      ["a","z"]
    ]
 */

#include "HashTable.h"

string shift(string const& s) {
    string t;
    for (int i = 1; i < s.size(); ++i) {
        int diff = s[i] - s[i - 1];
        if (diff < 0) diff += 26;
        t += 'a' + diff;
    }
    return t;
}

vector<vector<string>> groupStrings(vector<string>& strings) {
    unordered_map<string, vector<string>> mp;
    for (string const& s : strings) {
        mp[shift(s)].push_back(s);
    }
    vector<vector<string>> groups;
    for (auto m : mp) {
        vector<string> group = m.second;
        sort(group.begin(), group.end());
        groups.push_back(group);
    }
    return groups;
}
