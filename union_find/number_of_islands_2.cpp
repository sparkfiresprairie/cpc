//
// Created by Xingyuan Wang on 3/15/17.
//

/*
    A 2d grid map of m rows and n columns is initially filled with water. We may
    perform an addLand operation which turns the water at position (row, col)
    into a land. Given a list of positions to operate, count the number of
    islands after each addLand operation. An island is surrounded by water and
    is formed by connecting adjacent lands horizontally or vertically. You may
    assume all four edges of the grid are all surrounded by water.

    Example:

    Given m = 3, n = 3, positions = [[0,0], [0,1], [1,2], [2,1]].
    Initially, the 2d grid grid is filled with water. (Assume 0 represents water
    and 1 represents land).

    0 0 0
    0 0 0
    0 0 0
    Operation #1: addLand(0, 0) turns the water at grid[0][0] into a land.

    1 0 0
    0 0 0   Number of islands = 1
    0 0 0
    Operation #2: addLand(0, 1) turns the water at grid[0][1] into a land.

    1 1 0
    0 0 0   Number of islands = 1
    0 0 0
    Operation #3: addLand(1, 2) turns the water at grid[1][2] into a land.

    1 1 0
    0 0 1   Number of islands = 2
    0 0 0
    Operation #4: addLand(2, 1) turns the water at grid[2][1] into a land.

    1 1 0
    0 0 1   Number of islands = 3
    0 1 0
    We return the result as an array: [1, 1, 2, 3]

    Challenge:

    Can you do it in time complexity O(k log mn), where k is the length of the
    positions?
 */

#include "UnionFind.h"

int findRoot(vector<int>& root, int idx) {
    while (root[idx] != idx) {
        // path_compression: make idx's grandparent its parent
        root[idx] = root[root[idx]];
        idx = root[idx];
    }
    return idx;
}

vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
    vector<int> island_nums;
    if (m <= 0 || n <= 0) return island_nums;
    vector<int> dirs{1, 0, -1, 0, 1};
    vector<int> root(m * n, -1);        // one island = one tree
    int count = 0;                      // number of islands
    for (auto const& p : positions) {
        int idx = p.first * n + p.second;
        ++count;                        // add new island
        root[idx] = idx;                // assume new point is isolated island
        for (int i = 0; i < 4; ++i) {
            int x = p.first + dirs[i];
            int y = p.second + dirs[i + 1];
            int nb_idx = x * n + y;
            if (x < 0 || x >= m || y < 0 || y >= n || root[nb_idx] == -1) continue;
            int root_of_nb = findRoot(root, nb_idx);
            if (root_of_nb != idx) {        // if neighbor is in another island
                root[idx] = root_of_nb;     // union two islands
                idx = root_of_nb;           // current tree root = joined tree root!!!!
                --count;
            }
        }
        island_nums.push_back(count);
    }
    return island_nums;
}


