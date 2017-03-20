//
// Created by Xingyuan Wang on 3/19/17.
//

/*
    Given a string array words, find the maximum value of length(word[i]) * length(word[j])
    where the two words do not share common letters. You may assume that each word will
    contain only lower case letters. If no such two words exist, return 0.

    Example 1:
    Given ["abcw", "baz", "foo", "bar", "xtfn", "abcdef"]
    Return 16
    The two words can be "abcw", "xtfn".

    Example 2:
    Given ["a", "ab", "abc", "d", "cd", "bcd", "abcd"]
    Return 4
    The two words can be "ab", "cd".

    Example 3:
    Given ["a", "aa", "aaa", "aaaa"]
    Return 0
    No such pair of words.
 */

#include "BitManipulation.h"

int maxProduct(vector<string>& words) {
    int n = words.size();
    vector<int> value(n, 0);
    for (int i = 0; i < n; ++i) {
        for (auto c : words[i]) {
            value[i] |= 1 << (c - 'a');
        }
    }
    int max_product = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int t = words[i].size() * words[j].size();
            if ((value[i] & value[j]) == 0) max_product = max(max_product, t);
        }
    }
    return max_product;
}

// time: O(n^2)
// space: O(n)