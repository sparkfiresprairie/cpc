//
// Created by Xingyuan Wang on 3/17/17.
//

/*
    Given a non-empty string, encode the string such that its encoded length is
    the shortest.

    The encoding rule is: k[encoded_string], where the encoded_string inside the
    square brackets is being repeated exactly k times.

    Note:
    k will be a positive integer and encoded string will not be empty or have
    extra space.
    You may assume that the input string contains only lowercase English letters.
    The string's length is at most 160.
    If an encoding process does not make the string shorter, then do not encode it.
    If there are several solutions, return any of them is fine.
    Example 1:

    Input: "aaa"
    Output: "aaa"
    Explanation: There is no way to encode it such that it is shorter than the
    input string, so we do not encode it.
    Example 2:

    Input: "aaaaa"
    Output: "5[a]"
    Explanation: "5[a]" is shorter than "aaaaa" by 1 character.
    Example 3:

    Input: "aaaaaaaaaa"
    Output: "10[a]"
    Explanation: "a9[a]" or "9[a]a" are also valid solutions, both of them have the
    same length = 5, which is the same as "10[a]".
    Example 4:

    Input: "aabcaabcd"
    Output: "2[aabc]d"
    Explanation: "aabc" occurs twice, so one answer can be "2[aabc]d".
    Example 5:

    Input: "abbbabbbcabbbabbbc"
    Output: "2[2[abbb]c]"
    Explanation: "abbbabbbc" occurs twice, but "abbbabbbc" can also be encoded to
    "2[abbb]c", so one answer can be "2[2[abbb]c]".
 */

#include "DynamicProgramming.h"

// The explanation for why that works is pretty straight forward.
// Consider a string S="helloworld". Now, given another
// string T="lloworldhe", can we figure out if T is a rotated
// version of S? Yes, we can! We check if S is a substring of T+T.
// Fine. How do we apply that to this problem? We consider every
// rotation of string S such that it's rotated by k units [k < len(S)]
// to the left. Specifically, we're looking at strings "elloworldh",
// "lloworldhe", "loworldhel", etc...
// If we have a string that is periodic (i.e. is made up of strings
// that are the same and repeat R times), then we can check if the
// string is equal to some rotation of itself, and if it is, then we
// know that the string is periodic. Checking if S is a sub-string
// of (S+S)[1:-1] basically checks if the string is present in a
// rotation of itself for all values of R such that 0 < R < len(S).

// if a string is equal to some rotation of itself, then the string is
// periodic
// only consider strings that are periodic
string collapse(string const& s, int i, int j, vector<vector<string>> const& dp) {
    string t = s.substr(i, j - i + 1);
    auto pos = (t + t).find(t, 1);
    if (pos >= t.size()) return t;
    // pos is the length of each period
    return to_string(t.size() / pos) + '[' + dp[i][i + pos - 1] + ']';
}

string encode(string s) {
    int n = s.size();
    vector<vector<string>> dp(n, vector<string>(n, ""));
    for (int len = 1; len <= n; ++len) {
        for (int i = 0; i + len - 1 < n; ++i) {
            int j = i + len - 1;
            dp[i][j] = s.substr(i, len);
            for (int k = i; k < j; ++k) {
                auto left = dp[i][k];
                auto right = dp[k + 1][j];
                if (left.size() + right.size() < dp[i][j].size()) {
                    dp[i][j] = left + right;
                }
            }
            string replace = collapse(s, i, j, dp);
            if (replace.size() < dp[i][j].size()) {
                dp[i][j] = replace;
            }
        }
    }
    return dp[0][n - 1];
}
