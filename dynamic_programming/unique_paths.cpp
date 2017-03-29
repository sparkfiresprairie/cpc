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
//    vector<vector<int>> grid(m, vector<int>(n, 0));
//    grid[0][0] = 1;
//    for (int j = 0; j < n; j += 1) {
//        for (int i = 0; i < m; i += 1) {
//            if (i - 1 >= 0) grid[i][j] += grid[i - 1][j];
//            if (j - 1 >= 0) grid[i][j] += grid[i][j - 1];
//        }
//    }
//    return grid[m - 1][n - 1];
//}

// time: O(mn)
// space: O(mn)

int uniquePaths(int m, int n) {
    if (m > n) return uniquePaths(n, m);
    vector<int> pre(m, 1);
    vector<int> cur(m, 1);
    for (int j = 1; j < n; ++j) {
        for (int i = 1; i < m; ++i) {
            cur[i] = cur[i - 1] + pre[i];
        }
        swap(pre, cur);
    }
    return pre[m - 1];
}

// time: O(mn)
// space: O(min(m,n))
