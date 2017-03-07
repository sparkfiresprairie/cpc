//
// Created by Xingyuan Wang on 3/6/17.
//

/*
    Given a list of words and two words word1 and word2, return the shortest distance between
    these two words in the list.

    For example,
    Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

    Given word1 = “coding”, word2 = “practice”, return 3.
    Given word1 = "makes", word2 = "coding", return 1.

    Note:
    You may assume that word1 does not equal to word2, and word1 and word2 are both in the list.
 */

#include "Array.h"

int shortestDistance(vector<string>& words, string word1, string word2) {
    int ans = std::numeric_limits<int>::max();
    int i = -1, j = -1;
    for (int k = 0; k < words.size(); ++k) {
        if (words[k] == word1) i = k;
        if (words[k] == word2) j = k;
        if (i != -1 & j != -1) ans = min(ans, abs(i - j));
    }
    return ans;
}

// time: O(n)
// space: O(1)