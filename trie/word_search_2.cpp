//
// Created by Xingyuan Wang on 4/13/17.
//

/*
    Given a 2D board and a list of words from the dictionary, find all words in the board.

    Each word must be constructed from letters of sequentially adjacent cell, where "adjacent"
    cells are those horizontally or vertically neighboring. The same letter cell may not be
    used more than once in a word.

    For example,
    Given words = ["oath","pea","eat","rain"] and board =

    [
      ['o','a','a','n'],
      ['e','t','a','e'],
      ['i','h','k','r'],
      ['i','f','l','v']
    ]
    Return ["eat","oath"].
    Note:
    You may assume that all inputs are consist of lowercase letters a-z.

    click to show hint.

    You would need to optimize your backtracking to pass the larger test. Could you stop
    backtracking earlier?

    If the current candidate does not exist in all words' prefix, you could stop backtracking
    immediately. What kind of data structure could answer such query efficiently? Does a hash
    table work? Why or why not? How about a Trie? If you would like to learn how to implement
    a basic trie, please work on this problem: Implement Trie (Prefix Tree) first.
 */

#include "Trie.h"

class TrieNode {
public:
    string word;
    vector<TrieNode*> children;
    TrieNode() : word(""), children(26, nullptr) {}
    ~TrieNode() {
        for (int i = 0; i < 26; ++i) {
            delete children[i];
        }
    }
};

void dfs(vector<vector<char>>& board, int i, int j, TrieNode* p, vector<string>& ans) {
    char c = board[i][j];
    int idx = c - 'a';
    if (!p->children[idx]) return;
    int m = board.size(), n = board[0].size();
    p = p->children[idx];
    if (p->word != "") {    // found one word
        ans.push_back(p->word);
        p->word = "";       // re-duplicate
    }
    vector<int> dir{0, 1, 0, -1, 0};
    board[i][j] = '.';
    for (int k = 0; k < 4; ++k) {
        int x = i + dir[k];
        int y = j + dir[k + 1];
        if (x >= 0 && x < m && y >= 0 && y < n && board[x][y] != '.') dfs(board, x, y, p, ans);
    }
    board[i][j] = c;
}

vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    vector<string> ans;
    if (board.empty() || board[0].empty() || words.empty()) return ans;

    // build Trie;
    TrieNode* root = new TrieNode();
    for (string const& word : words) {
        TrieNode* p = root;
        for (auto c : word) {
            int i = c - 'a';
            if (!p->children[i]) {
                p->children[i] = new TrieNode();
            }
            p = p->children[i];
        }
        p->word = word;
    }

    // dfs
    int m = board.size();
    int n = board[0].size();
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            dfs(board, i, j, root, ans);
        }
    }
    return ans;
}