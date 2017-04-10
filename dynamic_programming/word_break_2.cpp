//
// Created by Xingyuan Wang on 4/8/17.
//

/*
    Given a non-empty string s and a dictionary wordDict containing a list of non-empty
    words, add spaces in s to construct a sentence where each word is a valid dictionary
    word. You may assume the dictionary does not contain duplicate words.

    Return all such possible sentences.

    For example, given
    s = "catsanddog",
    dict = ["cat", "cats", "and", "sand", "dog"].

    A solution is ["cats and dog", "cat sand dog"].
 */

#include "DynamicProgramming.h"

vector<string> generateWords(vector<vector<string>> const& dp, int n) {
    if (n == 0) return vector<string>{""};
    vector<string> ans;
    for (int i = 0; i < dp[n].size(); ++i) {
        string right = dp[n][i];
        vector<string> lefts = generateWords(dp, n - right.size());
        for (auto const& left : lefts) {
            if (left == "") ans.push_back(left + right);
            else ans.push_back(left + " " + right);
        }
    }
    return ans;
}

vector<string> wordBreak(string s, vector<string>& wordDict) {
    if (s.empty()) return {};
    unordered_set<string> dict(wordDict.begin(), wordDict.end());
    int n = s.size();
    vector<vector<string>> dp(n + 1);
    dp[0].push_back("");
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < i; ++j) {
            string right = s.substr(j, i - j);
            if (!dp[j].empty() && dict.find(right) != dict.end()) {
                dp[i].push_back(right);
            }
        }
    }
    return generateWords(dp, n);
}



