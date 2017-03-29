//
// Created by Xingyuan Wang on 3/28/17.
//

/*
    Follow up for "Unique Paths":

    Now consider if some obstacles are added to the grids. How many unique paths
    would there be?

    An obstacle and empty space is marked as 1 and 0 respectively in the grid.

    For example,
    There is one obstacle in the middle of a 3x3 grid as illustrated below.

    [
      [0,0,0],
      [0,1,0],
      [0,0,0]
    ]
    The total number of unique paths is 2.

    Note: m and n will be at most 100.
 */

#include "DynamicProgramming.h"

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size(), n = obstacleGrid[0].size();
    vector<int> pre(n, 0);
    int step = 1;
    for (int j = 0; j < n; ++j) {
        if (obstacleGrid[0][j] == 1) step = 0;
        pre[j] = step;
    }
    for (int i = 1; i < m; ++i) {
        vector<int> cur(n, 0);
        for (int j = 0; j < n; ++j) {
            if (obstacleGrid[i][j] == 1){
                cur[j] = 0;
            } else {
                cur[j] += pre[j];
                if (j > 0) cur[j] += cur[j - 1];
            }

        }
        pre = cur;
    }
    return pre[n - 1];
}

// time: O(mn)
// space: O(min(m,n))

//int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//    int m = obstacleGrid.size(), n = obstacleGrid[0].size();
//    vector<int> dp(n, 0);
//    dp[0] = 1;
//    for (int i = 0; i < m; ++i) {
//        for (int j = 0; j < n; ++j) {
//            if (obstacleGrid[i][j] == 1) dp[j] = 0;
//            else if (j > 0) dp[j] += dp[j - 1];
//        }
//    }
//    return dp[n - 1];
//}