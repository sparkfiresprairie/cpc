//
// Created by Xingyuan Wang on 3/10/17.
//

/*
    Given a pattern and a string str, find if str follows the same pattern.

    Here follow means a full match, such that there is a bijection between a letter in
    pattern and a non-empty word in str.

    Examples:
    pattern = "abba", str = "dog cat cat dog" should return true.
    pattern = "abba", str = "dog cat cat fish" should return false.
    pattern = "aaaa", str = "dog cat cat dog" should return false.
    pattern = "abba", str = "dog dog dog dog" should return false.
    Notes:
    You may assume pattern contains only lowercase letters, and str contains lowercase
    letters separated by a single space.
 */

#include "HashTable.h"

bool wordPattern(string pattern, string str) {
    unordered_map<char, string> ctos;
    unordered_map<string, char> stoc;
    stringstream ss(str);
    string token;
    int i = 0;
    while(std::getline(ss, token, ' ')) {
        if (i >= pattern.size()) return false;
        if (ctos.find(pattern[i]) == ctos.end() && stoc.find(token) == stoc.end()) {
            ctos.insert({pattern[i], token});
            stoc.insert({token, pattern[i]});
        } else if (ctos[pattern[i]] != token) {
            return false;
        }
        ++i;
    }
    return i == pattern.size();
}

// time: O(n)
// space: O(n)