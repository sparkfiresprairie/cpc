//
// Created by Xingyuan Wang on 3/12/17.
//

/*
    Given two words (beginWord and endWord), and a dictionary's word list, find the
    length of shortest transformation sequence from beginWord to endWord, such that:

    Only one letter can be changed at a time.
    Each transformed word must exist in the word list. Note that beginWord is not a
    transformed word.
    For example,

    Given:
    beginWord = "hit"
    endWord = "cog"
    wordList = ["hot","dot","dog","lot","log","cog"]
    As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
    return its length 5.

    Note:
    Return 0 if there is no such transformation sequence.
    All words have the same length.
    All words contain only lowercase alphabetic characters.
    You may assume no duplicates in the word list.
    You may assume beginWord and endWord are non-empty and are not the same.
    UPDATE (2017/1/20):
    The wordList parameter had been changed to a list of strings (instead of a set of
    strings). Please reload the code definition to get the latest changes.
 */

#include "DFSBFS.h"

void add_candidates(string& word, unordered_set<string>& word_list, queue<string>& q) {
    word_list.erase(word);
    for (int i = 0; i < word.size(); ++i) {
        char c = word[i];
        for (int j = 0; j < 26; ++j) {
            word[i] = 'a' + j;
            if (word_list.find(word) != word_list.end()) {
                q.push(word);
                word_list.erase(word);
            }
        }
        word[i] = c;
    }
}

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> word_list(wordList.begin(), wordList.end());
    if (word_list.find(endWord) == word_list.end()) return 0;
    queue<string> q;
    add_candidates(beginWord, word_list, q);
    int level = 1;
    while (!q.empty()) {
        ++level;
        int sz = q.size();
        for (int i = 0; i < sz; ++i) {
            string s = q.front();
            q.pop();
            if (s == endWord) {
                return level;
            }
            add_candidates(s, word_list, q);
        }
    }
    return 0;
}

