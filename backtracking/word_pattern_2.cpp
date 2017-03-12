//
// Created by Xingyuan Wang on 3/10/17.
//

/*
    Given a pattern and a string str, find if str follows the same pattern.

    Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty substring in str.

    Examples:
    pattern = "abab", str = "redblueredblue" should return true.
    pattern = "aaaa", str = "asdasdasdasd" should return true.
    pattern = "aabb", str = "xyzabcxzyabc" should return false.
    Notes:
    You may assume both pattern and str contains only lowercase letters.
 */

#include "BackTracking.h"

bool help(string const& pattern, int pb, string const& str, int sb, unordered_map<char, string>& mp, unordered_set<string>& st) {
    if (pb == pattern.size()) return sb == str.size();
    char c = pattern[pb];
    if (mp.find(c) != mp.end()) {
        string const& value = mp[c];
        if (str.size() - sb < value.size() || str.substr(sb, value.size()) != value) return false;
        if (help(pattern, pb + 1, str, sb + value.size(), mp, st)) return true;
    } else {
        for (int i = sb; i < str.size(); ++i) {
            string value = str.substr(sb, i - sb + 1);
            if (st.find(value) != st.end()) continue;
            mp.insert({c, value});
            st.insert(value);
            if (help(pattern, pb + 1, str, sb + value.size(), mp, st)) return true;
            st.erase(value);
            mp.erase(c);
        }
    }
    return false;
}

bool wordPatternMatch(string pattern, string str) {
    unordered_map<char, string> mp;
    unordered_set<string> st;
    return help(pattern, 0, str, 0, mp, st);
}

