//
// Created by Xingyuan Wang on 4/13/17.
//

/*
    Given a 2D board and a word, find if the word exists in the grid.

    The word can be constructed from letters of sequentially adjacent cell, where
    "adjacent" cells are those horizontally or vertically neighboring. The same
    letter cell may not be used more than once.

    For example,
    Given board =

    [
      ['A','B','C','E'],
      ['S','F','C','S'],
      ['A','D','E','E']
    ]
    word = "ABCCED", -> returns true,
    word = "SEE", -> returns true,
    word = "ABCB", -> returns false.
 */

#include "DFSBFS.h"

bool dfs(vector<vector<char>>& board, string const& word, int i, int j, int b) {
    int m = board.size(), n = board[0].size();
    if (b >= word.size()) return true;
    if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != word[b]) return false;
    vector<int> dir{0, 1, 0, -1, 0};
    char c = board[i][j];
    board[i][j] = 0;
    for (int k = 0; k < 4; ++k) {
        if (dfs(board, word, i + dir[k], j + dir[k + 1], b + 1)) return true;
    }
    board[i][j] = c;
    return false;
}

bool exist(vector<vector<char>>& board, string word) {
    if (board.empty() || board[0].empty()) return false;
    if (word.empty()) return false;
    int m = board.size(), n = board[0].size();
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (dfs(board, word, i, j, 0)) return true;
        }
    }
    return false;
}



