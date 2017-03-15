//
// Created by Xingyuan Wang on 3/14/17.
//

/*
    Given two sparse matrices A and B, return the result of AB.

    You may assume that A's column number is equal to B's row number.

    Example:

    A = [
      [ 1, 0, 0],
      [-1, 0, 3]
    ]

    B = [
      [ 7, 0, 0 ],
      [ 0, 0, 0 ],
      [ 0, 0, 1 ]
    ]


         |  1 0 0 |   | 7 0 0 |   |  7 0 0 |
    AB = | -1 0 3 | x | 0 0 0 | = | -7 0 3 |
                      | 0 0 1 |
 */

#include "Math.h"

vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
    int m = A.size(), r = A[0].size(), n = B[0].size();
    vector<vector<int>> ans(m, vector<int>(n, 0));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < r; ++j) {
            if (A[i][j] != 0) {
                for (int k = 0; k < n; ++k) {
                    if (B[j][k] != 0) ans[i][k] += A[i][j] * B[j][k];
                }
            }
        }
    }
    return ans;
}

// time: O(mnr)
// space: O(mn)