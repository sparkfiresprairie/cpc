//
// Created by Xingyuan Wang on 3/17/17.
//

/*
    Given a 2D grid, each cell is either a wall 'W', an enemy 'E' or empty '0'
    (the number zero), return the maximum enemies you can kill using one bomb.
    The bomb kills all the enemies in the same row and column from the planted
    point until it hits the wall since the wall is too strong to be destroyed.
    Note that you can only put the bomb at an empty cell.

    Example:
    For the given grid

    0 E 0 0
    E 0 W E
    0 E 0 0

    return 3. (Placing a bomb at (1,1) kills 3 enemies)
 */

#include "DynamicProgramming.h"

int maxKilledEnemies(vector<vector<char>>& grid) {
    if (grid.empty() || grid[0].empty()) return 0;
    int m = grid.size();
    int n = grid[0].size();
    int ans = 0;
    int rowhits;
    vector<int> colhits(n, 0);
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (j == 0 || grid[i][j - 1] == 'W') {
                rowhits = 0;
                for (int k = j; k < n && grid[i][k] != 'W'; ++k) {
                    if (grid[i][k] == 'E') ++rowhits;
                }
            }
            if (i == 0 || grid[i - 1][j] == 'W') {
                colhits[j] = 0;
                for (int k = i; k < m && grid[k][j] != 'W'; ++k) {
                    if (grid[k][j] == 'E') ++colhits[j];
                }
            }
            if (grid[i][j] == '0') {
                ans = max(ans, rowhits + colhits[j]);
            }
        }
    }
    return ans;
}

