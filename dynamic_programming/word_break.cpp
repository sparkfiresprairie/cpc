//
// Created by Xingyuan Wang on 3/26/17.
//

/*
    Given a non-empty string s and a dictionary wordDict containing a list of
    non-empty words, determine if s can be segmented into a space-separated
    sequence of one or more dictionary words. You may assume the dictionary
    does not contain duplicate words.

    For example, given
    s = "leetcode",
    dict = ["leet", "code"].

    Return true because "leetcode" can be segmented as "leet code".
 */

#include "DynamicProgramming.h"

bool wordBreak(string s, vector<string>& wordDict) {
    if (s.empty()) return false;
    unordered_set<string> dict(wordDict.begin(), wordDict.end());
    int n = s.size();
    vector<bool> dp(n + 1, false);
    dp[0] = true;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (dp[j] && dict.find(s.substr(j, i - j)) != dict.end()) {
                dp[i] = true;
                break;
            }
        }
    }
    return dp[n];
}

// time: O(n^2) n is length of s
// space: O(max(n, m)) m is size of wordDict

//bool wordBreak(string s, unordered_set<string>& wordDict) {
//    unordered_map<string, bool> mem;
//    return help(s, 0, wordDict, mem);
//}
//
//bool help(string const& s, int b, unordered_set<string>& wordDict, unordered_map<string, bool>& mem) {
//    if (b >= s.size()) return true;
//    string tail = s.substr(b);
//    if (mem.find(tail) != mem.end()) return mem[tail];
//    bool ans = false;
//    for (int i = b; i < s.size(); ++i) {
//        string t = s.substr(b, i - b + 1);
//        if (wordDict.find(t) != wordDict.end()) ans = ans || help(s, i + 1, wordDict, mem);
//    }
//    mem[tail] = ans;
//    return ans;
//}