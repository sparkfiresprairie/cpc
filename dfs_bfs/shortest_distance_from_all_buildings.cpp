//
// Created by Xingyuan Wang on 3/14/17.
//

/*
    You want to build a house on an empty land which reaches all buildings in the shortest
    amount of distance. You can only move up, down, left and right. You are given a 2D grid
    of values 0, 1 or 2, where:

    Each 0 marks an empty land which you can pass by freely.
    Each 1 marks a building which you cannot pass through.
    Each 2 marks an obstacle which you cannot pass through.
    For example, given three buildings at (0,0), (0,4), (2,2), and an obstacle at (0,2):

    1 - 0 - 2 - 0 - 1
    |   |   |   |   |
    0 - 0 - 0 - 0 - 0
    |   |   |   |   |
    0 - 0 - 1 - 0 - 0
    The point (1,2) is an ideal empty land to build a house, as the total travel distance
    of 3+3+1=7 is minimal. So return 7.
 */

#include "DFSBFS.h"

void bfs(vector<vector<int>> const& grid, int i, int j, vector<vector<int>>& dist, vector<vector<int>>& reach) {
    int m = grid.size(), n = grid[0].size();
    queue<pair<int, int>> q;
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    vector<int> dirs{1, 0, -1, 0, 1};
    q.push({i, j});
    visited[i][j] = true;
    int level = 0;
    while (!q.empty()) {
        int sz = q.size();
        ++level;
        for (int k = 0; k < sz; ++k) {
            auto ij = q.front();
            q.pop();
            for (int idx = 0; idx < 4; ++idx) {
                int x = ij.first + dirs[idx];
                int y = ij.second + dirs[idx + 1];
                if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 0 && !visited[x][y]) {
                    q.push({x, y});
                    visited[x][y] = true;
                    dist[x][y] += level;
                    ++reach[x][y];
                }
            }
        }
    }
}

int shortestDistance(vector<vector<int>>& grid) {
    if (grid.empty() || grid[0].empty()) return -1;
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> dist(m, vector<int>(n, 0));
    vector<vector<int>> reach(dist);
    int building_num = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == 1) {
                ++building_num;
                bfs(grid, i, j, dist, reach);
            }
        }
    }

    int shortest = std::numeric_limits<int>::max();
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == 0 && reach[i][j] == building_num) {
                shortest = min(shortest, dist[i][j]);
            }
        }
    }

    return shortest == std::numeric_limits<int>::max() ? -1 : shortest;
}

// time: O(mn)
// space: O(mn)