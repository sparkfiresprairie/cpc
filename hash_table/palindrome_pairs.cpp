//
// Created by Xingyuan Wang on 3/20/17.
//

/*
    Given a list of unique words, find all pairs of distinct indices (i, j)
    in the given list, so that the concatenation of the two words, i.e.
    words[i] + words[j] is a palindrome.

    Example 1:
    Given words = ["bat", "tab", "cat"]
    Return [[0, 1], [1, 0]]
    The palindromes are ["battab", "tabbat"]
    Example 2:
    Given words = ["abcd", "dcba", "lls", "s", "sssll"]
    Return [[0, 1], [1, 0], [3, 2], [2, 4]]
    The palindromes are ["dcbaabcd", "abcddcba", "slls", "llssssll"]
 */

#include "HashTable.h"

bool is_palindrome(string const& s) {
    int i = 0, j = s.size() -1;
    while (i <= j) {
        if (s[i++] != s[j--]) return false;
    }
    return true;
}

// The <= in for (int j=0; j<=words[i].length(); j++) is aimed to
// handle empty string in the input. Consider the test case of ["a", ""];
// Since we now use <= in for (int j=0; j<=words[i].length(); j++)
// instead of <. There may be duplicates in the output (consider test
// case ["abcd", "dcba"]). Therefore I put a str2.length()!=0 to avoid
// duplicates.
vector<vector<int>> palindromePairs(vector<string>& words) {
    vector<vector<int>> ans;
    if (words.empty()) return ans;
    unordered_map<string, int> mp;
    for (int i = 0; i < words.size(); ++i) {
        mp.insert({words[i], i});
    }
    for (int i = 0; i < words.size(); ++i) {
        for (int j = 0; j <= words[i].size(); ++j) {
            string s1 = words[i].substr(0, j);
            string s2 = words[i].substr(j);
            if (is_palindrome(s1)) {
                string s2_reverse = s2;
                reverse(s2_reverse.begin(), s2_reverse.end());
                if (mp.find(s2_reverse) != mp.end() && mp[s2_reverse] != i) {
                    ans.push_back(vector<int>{mp[s2_reverse], i});
                }
            }

            if (is_palindrome(s2)) {
                string s1_reverse = s1;
                reverse(s1_reverse.begin(), s1_reverse.end());
                if (mp.find(s1_reverse) != mp.end() && mp[s1_reverse] != i && s2.size() != 0) {
                    ans.push_back(vector<int>{i, mp[s1_reverse]});
                }
            }
        }
    }
    return ans;
}

// time: O(n*k^2)
// space: O(n)