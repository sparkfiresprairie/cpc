//
// Created by Xingyuan Wang on 2/26/17.
//

/*
    Given a 2D binary matrix filled with 0's and 1's, find the largest square
    containing only 1's and return its area.

    For example, given the following matrix:

    1 0 1 0 0
    1 0 1 1 1
    1 1 1 1 1
    1 0 0 1 0
    Return 4.
 */

#include "DynamicProgramming.h"

//int maximalSquare(vector<vector<char>>& matrix) {
//    if (matrix.empty() || matrix[0].empty()) return 0;
//    int m = matrix.size(), n = matrix[0].size();
//    vector<vector<int>> dp(m, vector<int>(n, 0));
//    int maxsize = 0;
//    for (int i = 0; i < m; ++i) {
//        dp[i][0] = matrix[i][0] - '0';
//        maxsize = max(maxsize, dp[i][0]);
//    }
//    for (int j = 0; j < n; ++j) {
//        dp[0][j] = matrix[0][j] - '0';
//        maxsize = max(maxsize, dp[0][j]);
//    }
//    for (int i = 1; i < m; ++i) {
//        for (int j = 1; j < n; ++j) {
//            if (matrix[i][j] == '0') dp[i][j] = 0;
//            else {
//                dp[i][j] = 1 + min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]);
//                maxsize = max(maxsize, dp[i][j]);
//            }
//        }
//    }
//    return maxsize * maxsize;
//}

// time: O(n*n)
// space: O(n*n)

int maximalSquare(vector<vector<char>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) return 0;
    int m = matrix.size(), n = matrix[0].size();
    vector<int> pre(n, 0);
    vector<int> cur(n, 0);
    int maxsize = 0;
    for (int j = 0; j < n; ++j) {
        pre[j] = matrix[0][j] - '0';
        maxsize = max(maxsize, pre[j]);
    }
    for (int i = 1; i < m; ++i) {
        cur[0] = matrix[i][0] - '0';
        maxsize = max(maxsize, cur[0]);
        for (int j = 1; j < n; ++j) {
            if (matrix[i][j] == '0') cur[j] = 0;
            else {
                cur[j] = 1 + min(min(pre[j], pre[j - 1]), cur[j - 1]);
                maxsize = max(maxsize, cur[j]);
            }
        }
        swap(pre, cur);
    }
    return maxsize * maxsize;
}

// time: O(n*n)
// space: O(n);


