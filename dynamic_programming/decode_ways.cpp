//
// Created by Xingyuan Wang on 3/25/17.
//

/*
    A message containing letters from A-Z is being encoded to numbers using
    the following mapping:

    'A' -> 1
    'B' -> 2
    ...
    'Z' -> 26
    Given an encoded message containing digits, determine the total number
    of ways to decode it.

    For example,
    Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

    The number of ways decoding "12" is 2.
 */

#include "DynamicProgramming.h"

int numDecodings(string s) {
    if (s.empty()) return 0;
    int n = s.size();
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; ++i) {
        if (s[i - 1] != '0') dp[i] += dp[i - 1];
        if (i >= 2) {
            int num = stoi(s.substr(i - 2, 2));
            if (num >= 10 && num <= 26) {
                dp[i] += dp[i - 2];
            }
        }
    }
    return dp[n];
}

// time: O(n)
// space: O(n)