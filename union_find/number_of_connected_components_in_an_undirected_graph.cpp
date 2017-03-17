//
// Created by Xingyuan Wang on 3/17/17.
//

/*
    Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge
    is a pair of nodes), write a function to find the number of connected components
    in an undirected graph.

    Example 1:
         0          3
         |          |
         1 --- 2    4
    Given n = 5 and edges = [[0, 1], [1, 2], [3, 4]], return 2.

    Example 2:
         0           4
         |           |
         1 --- 2 --- 3
    Given n = 5 and edges = [[0, 1], [1, 2], [2, 3], [3, 4]], return 1.

    Note:
    You can assume that no duplicate edges will appear in edges. Since all edges are
    undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.
 */

#include "UnionFind.h"

int countComponents(int n, vector<pair<int, int>>& edges) {
    vector<int> parent(n, 0);
    vector<int> sz(n, 1);
    int count = n;
    for (int i = 0; i < n; ++i) {
        parent[i] = i;
    }
    for (auto const& edge : edges) {
        int root1 = edge.first;
        while (root1 != parent[root1]) {
            parent[root1] = parent[parent[root1]];
            root1 = parent[root1];
        }
        int root2 = edge.second;
        while (root2 != parent[root2]) {
            parent[root2] = parent[parent[root2]];
            root2 = parent[root2];
        }
        if (root1 == root2) continue;
        --count;
        if (sz[root1] > sz[root2]) {
            parent[root2] = root1;
            sz[root1] += sz[root2];
        } else {
            parent[root1] = root2;
            sz[root2] += sz[root1];
        }
    }
    return count;
}
