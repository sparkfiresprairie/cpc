//
// Created by Xingyuan Wang on 3/19/17.
//

/*
    Given an integer matrix, find the length of the longest increasing path.

    From each cell, you can either move to four directions: left, right, up or down.
    You may NOT move diagonally or move outside of the boundary (i.e. wrap-around is
    not allowed).

    Example 1:

    nums = [
      [9,9,4],
      [6,6,8],
      [2,1,1]
    ]
    Return 4
    The longest increasing path is [1, 2, 6, 9].

    Example 2:

    nums = [
      [3,4,5],
      [3,2,6],
      [2,2,1]
    ]
    Return 4
    The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.
 */

#include "DFSBFS.h"

int dfs(vector<vector<int>> const& matrix, int i, int j, vector<vector<int>>& memo) {
    if (memo[i][j] != 0) return memo[i][j];
    int m = matrix.size(), n = matrix[0].size();
    vector<int> dir{1, 0, -1, 0, 1};
    int longest = 0;
    for (int k = 0; k < 4; ++k) {
        int x = i + dir[k];
        int y = j + dir[k + 1];
        if (x >= 0 && x < m && y >= 0 && y < n && matrix[x][y] > matrix[i][j]) {
            longest = max(longest, dfs(matrix, x, y, memo));
        }
    }
    memo[i][j] = longest + 1;
    return longest + 1;
}

int longestIncreasingPath(vector<vector<int>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) return 0;
    int m = matrix.size(), n = matrix[0].size();
    vector<vector<int>> memo(m, vector<int>(n, 0));
    int longest = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            longest = max(longest, dfs(matrix, i, j, memo));
        }
    }
    return longest;
}

// time: O(mn)
// space: O(mn)


