//
// Created by Xingyuan Wang on 3/17/17.
//

/*
    Given a set of words (without duplicates), find all word squares you can build from them.

    A sequence of words forms a valid word square if the kth row and column read the exact
    same string, where 0 ≤ k < max(numRows, numColumns).

    For example, the word sequence ["ball","area","lead","lady"] forms a word square because
    each word reads the same both horizontally and vertically.

    b a l l
    a r e a
    l e a d
    l a d y
    Note:
    There are at least 1 and at most 1000 words.
    All words will have the exact same length.
    Word length is at least 1 and at most 5.
    Each word contains only lowercase English alphabet a-z.
    Example 1:

    Input:
    ["area","lead","wall","lady","ball"]

    Output:
    [
      [ "wall",
        "area",
        "lead",
        "lady"
      ],
      [ "ball",
        "area",
        "lead",
        "lady"
      ]
    ]

    Explanation:
    The output consists of two word squares. The order of output does not matter (just the
    order of words in each word square matters).
    Example 2:

    Input:
    ["abat","baba","atan","atal"]

    Output:
    [
      [ "baba",
        "abat",
        "baba",
        "atan"
      ],
      [ "baba",
        "abat",
        "baba",
        "atal"
      ]
    ]

    Explanation:
    The output consists of two word squares. The order of output does not matter (just the
    order of words in each word square matters).
 */

#include "Trie.h"

struct TrieNode {
    vector<int> indices;
    vector<TrieNode*> children;
    TrieNode() : children(26, nullptr) {}
    ~TrieNode() {
        for (int i = 0; i < 26; ++i) {
            delete children[i];
        }
    }
};

TrieNode* build_trie(vector<string> const& words) {
    TrieNode* root = new TrieNode();
    for (int i = 0; i < words.size(); ++i) {
        TrieNode* p = root;
        for (auto c : words[i]) {
            int idx = c - 'a';
            if (p->children[idx] == nullptr) p->children[idx] = new TrieNode();
            p = (p->children)[idx];
            (p->indices).push_back(i);
        }
    }
    return root;
}

void back_tracking(vector<string> const& words, int level, TrieNode* root, vector<string>& square, vector<vector<string>>& ans) {
    if (level >= words[0].size()) {
        ans.push_back(square);
        return;
    }
    string str;
    for (int i = 0; i < level; ++i) {
        str += square[i][level];
    }
    TrieNode* p = root;
    for (int i = 0; i < str.size(); ++i) {
        if (!(p = p->children[str[i] - 'a'])) return;
    }
    for (auto idx : p->indices) {
        square[level] = words[idx];
        back_tracking(words, level + 1, root, square, ans);
    }
}

vector<vector<string>> wordSquares(vector<string>& words) {
    if (words.empty()) return {};
    int n = words[0].size();
    TrieNode* trie = build_trie(words);
    vector<vector<string>> ans;
    vector<string> square(n);
    for (auto const& word :words) {
        square[0] = word;
        back_tracking(words, 1, trie, square, ans);
    }
    return ans;
}