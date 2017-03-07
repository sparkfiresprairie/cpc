//
// Created by Xingyuan Wang on 3/6/17.
//

/*
    This is a follow up of Shortest Word Distance. The only difference is now you are given the
    list of words and your method will be called repeatedly many times with different parameters.
    How would you optimize it?

    Design a class which receives a list of words in the constructor, and implements a method that
    takes two words word1 and word2 and return the shortest distance between these two words in
    the list.

    For example,
    Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

    Given word1 = “coding”, word2 = “practice”, return 3.
    Given word1 = "makes", word2 = "coding", return 1.

    Note:
    You may assume that word1 does not equal to word2, and word1 and word2 are both in the list.
 */

#include "HashTable.h"

class WordDistance {
    unordered_map<string, vector<int>> mp;
public:
    WordDistance(vector<string> words) {
        for (int i = 0; i < words.size(); ++i) {
            mp[words[i]].push_back(i);
        }
    }

    int shortest(string word1, string word2) {
        auto const& v1 = mp[word1];
        auto const& v2 = mp[word2];
        int ans = INT_MAX;
        int i = 0, j = 0;
        while (i < v1.size() && j < v2.size()) {
            ans = min(ans, abs(v1[i] - v2[j]));
            if (v1[i] < v2[j])  {
                ++i;
                if (i >= v1.size()) break;
            }
            else {
                ++j;
                if (j >= v2.size()) break;
            }
        }
        return ans;
    }
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance obj = new WordDistance(words);
 * int param_1 = obj.shortest(word1,word2);
 */

// time: create-O(n) shortest-O(v1.size + v2.size)
// space: O(n)