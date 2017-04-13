//
// Created by Xingyuan Wang on 3/28/17.
//

/*
    A robot is located at the top-left corner of a m x n grid (marked 'Start' in the
    diagram below).

    The robot can only move either down or right at any point in time. The robot is
    trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram
    below).

    How many possible unique paths are there?

    Note: m and n will be at most 100.
 */

#include "DynamicProgramming.h"

//int uniquePaths(int m, int n) {
//    if (m == 0 || n == 0) return 0;
//    vector<vector<int>> dp(m, vector<int>(n, 0));
//    for (int i = 0; i < m; ++i) {
//        dp[i][0] = 1;
//    }
//    for (int j = 0; j < n; ++j) {
//        dp[0][j] = 1;
//    }
//    for (int i = 1; i < m; ++i) {
//        for (int j = 1; j < n; ++j) {
//            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
//        }
//    }
//    return dp[m - 1][n - 1];
//}

// time: O(mn)
// space: O(mn)

int uniquePaths(int m, int n) {
    if (m == 0 || n == 0) return 0;
    if (m < n) return uniquePaths(n, m);
    vector<int> pre(n, 1);
    vector<int> cur(n, 1);
    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            cur[j] = pre[j] + cur[j - 1];
        }
        swap(pre, cur);
    }
    return pre[n - 1];
}

// time: O(mn)
// space: O(min(m,n))
