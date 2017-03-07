//
// Created by Xingyuan Wang on 3/6/17.
//

/*
    This is a follow up of Shortest Word Distance. The only difference is now word1 could be
    the same as word2.

    Given a list of words and two words word1 and word2, return the shortest distance between
    these two words in the list.

    word1 and word2 may be the same and they represent two individual words in the list.

    For example,
    Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

    Given word1 = “makes”, word2 = “coding”, return 1.
    Given word1 = "makes", word2 = "makes", return 3.

    Note:
    You may assume word1 and word2 are both in the list.
 */

#include "Array.h"

int shortestWordDistance3(vector<string>& words, string word1, string word2) {
    bool is_same = word1 == word2;
    int ans = INT_MAX;
    int i = -1, j = -1;
    for (int k = 0; k < words.size(); ++k) {
        if (words[k] == word1) {
            i = k;
            if (is_same) {
                i = j;
                j = k;
            }
        } else if (words[k] == word2) {
            j = k;
        }
        if (i != -1 && j != -1) ans = min(ans, abs(i - j));
    }
    return ans;
}

// time: O(n)
// space: O(1)