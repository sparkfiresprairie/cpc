//
// Created by Xingyuan Wang on 3/21/17.
//

/*
    You have a number of envelopes with widths and heights given as a pair of
    integers (w, h). One envelope can fit into another if and only if both the
    width and height of one envelope is greater than the width and height of
    the other envelope.

    What is the maximum number of envelopes can you Russian doll? (put one
    inside other)

    Example:
    Given envelopes = [[5,4],[6,4],[6,7],[2,3]], the maximum number of envelopes
    you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).

    Show Company Tags
    Show Tags
    Hide Similar Problems
 */

#include "DynamicProgramming.h"

int maxEnvelopes(vector <pair<int, int>> &envelopes) {
    if (envelopes.empty()) return 0;
    auto my_less = [](pair<int, int> const &a, pair<int, int> const &b) {
        return a.first < b.first;
    };
    sort(envelopes.begin(), envelopes.end(), my_less);
    vector<int> dp(envelopes.size(), 1);
    int longest = 1;
    for (int i = 1; i < envelopes.size(); ++i) {
        for (int j = 0; j < i; ++j) {
            if (envelopes[i].first != envelopes[j].first && envelopes[j].second < envelopes[i].second) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        longest = max(longest, dp[i]);
    }
    return longest;
}

// time: O(n^2)
// space: O(n)
