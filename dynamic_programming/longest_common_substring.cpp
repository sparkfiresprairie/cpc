//
// Created by Xingyuan Wang on 3/27/17.
//

/*
    Given two strings ‘X’ and ‘Y’, find the length of the longest common substring.
 */

#include "DynamicProgramming.h"

// dp[i][j] is the length of the longest common suffix for all substrings

int longestCommonSubstring(string const& s, string const& t) {
    int m = s.size(), n = t.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    int longest = 0;
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (s[i - 1] == t[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                longest = max(longest, dp[i][j]);
            }
            else dp[i][j] = 0;
        }
    }
    return longest;
}


// time: O(mn)
// space: O(mn)