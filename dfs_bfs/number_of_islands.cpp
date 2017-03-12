//
// Created by Xingyuan Wang on 3/12/17.
//

/*
    Given a 2d grid map of '1's (land) and '0's (water), count the number of islands.
    An island is surrounded by water and is formed by connecting adjacent lands
    horizontally or vertically. You may assume all four edges of the grid are all
    surrounded by water.

    Example 1:

    11110
    11010
    11000
    00000
    Answer: 1

    Example 2:

    11000
    11000
    00100
    00011
    Answer: 3
 */

#include "DFSBFS.h"

void dfs(vector<vector<char>>& grid, int m, int n, int i, int j) {
    grid[i][j] = '0';
    vector<int> dir{1, 0, -1, 0, 1};
    for (int k = 0; k < 4; ++k) {
        int x = i + dir[k];
        int y = j + dir[k + 1];
        if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == '1') dfs(grid, m, n, x, y);
    }
}

int numIslands(vector<vector<char>>& grid) {
    if (grid.empty() || grid[0].empty()) return 0;
    int m = grid.size(), n = grid[0].size();
    int sum = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == '1') {
                ++sum;
                dfs(grid, m, n, i, j);
            }
        }
    }
    return sum;
}

// time: O(mn)
// space: O(m + n)
//
//void bfs(vector<vector<char>>& grid, int m, int n, int i, int j) {
//    vector<int> dir{1, 0, -1, 0, 1};
//    queue<pair<int, int>> q;
//    grid[i][j] = '0';
//    q.push({i, j});
//    while (!q.empty()) {
//        int s = q.front().first;
//        int t = q.front().second;
//        q.pop();
//        for (int k = 0; k < 4; ++k) {
//            int x = s + dir[k];
//            int y = t + dir[k + 1];
//            if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == '1') {
//                grid[x][y] = '0';
//                q.push({x, y});
//            }
//        }
//    }
//}
//
//int numIslands(vector<vector<char>>& grid) {
//    if (grid.empty() || grid[0].empty()) return 0;
//    int m = grid.size(), n = grid[0].size();
//    int sum = 0;
//    for (int i = 0; i < m; ++i) {
//        for (int j = 0; j < n; ++j) {
//            if (grid[i][j] == '1') {
//                ++sum;
//                bfs(grid, m, n, i, j);
//            }
//        }
//    }
//    return sum;
//}

