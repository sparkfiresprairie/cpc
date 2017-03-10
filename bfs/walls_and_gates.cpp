//
// Created by Xingyuan Wang on 3/9/17.
//

/*
    You are given a m x n 2D grid initialized with these three possible values.

    -1 - A wall or an obstacle.
    0 - A gate.
    INF - Infinity means an empty room. We use the value 231 - 1 = 2147483647 to represent
    INF as you may assume that the distance to a gate is less than 2147483647.
    Fill each empty room with the distance to its nearest gate. If it is impossible to
    reach a gate, it should be filled with INF.

    For example, given the 2D grid:
    INF  -1  0  INF
    INF INF INF  -1
    INF  -1 INF  -1
      0  -1 INF INF
    After running your function, the 2D grid should be:
      3  -1   0   1
      2   2   1  -1
      1  -1   2  -1
      0  -1   3   4
    Show Company Tags
    Hide Tags
 */

#include "BFS.h"

void bfs(vector<vector<int>>& rooms, int row, int col) {
    int m = rooms.size(), n = rooms[0].size();
    vector<int> dirs{0, 1, 0, -1, 0};
    queue<pair<int, int>> q;
    q.push({row, col});
    int dist = 1;
    while (!q.empty()) {
        int sz = q.size();
        for (int k = 0; k < sz; ++k) {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            for (int t = 0; t < 4; ++t) {
                int x = i + dirs[t];
                int y = j + dirs[t + 1];
                if (x < 0 || x >= m || y < 0 || y >= n || rooms[x][y] < dist) continue;
                rooms[x][y] = dist;
                q.push({x, y});
            }
        }
        ++dist;
    }
}

void wallsAndGates(vector<vector<int>>& rooms) {
    if (rooms.empty() || rooms[0].empty()) return;
    int m = rooms.size(), n = rooms[0].size();
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (rooms[i][j] == 0) {
                bfs(rooms, i, j);
            }
        }
    }
}


