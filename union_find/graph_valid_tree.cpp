//
// Created by Xingyuan Wang on 3/7/17.
//

/*
    Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes),
    write a function to check whether these edges make up a valid tree.

    For example:

    Given n = 5 and edges = [[0, 1], [0, 2], [0, 3], [1, 4]], return true.

    Given n = 5 and edges = [[0, 1], [1, 2], [2, 3], [1, 3], [1, 4]], return false.

    Hint:

    Given n = 5 and edges = [[0, 1], [1, 2], [3, 4]], what should your return? Is this case a valid tree?
    According to the definition of tree on Wikipedia: “a tree is an undirected graph in which any two
    vertices are connected by exactly one path. In other words, any connected graph without simple cycles
    is a tree.”
    Note: you can assume that no duplicate edges will appear in edges. Since all edges are undirected,
    [0, 1] is the same as [1, 0] and thus will not appear together in edges.
 */

#include "UnionFind.h"

bool validTree(int n, vector<pair<int, int>>& edges) {
    vector<int> parent(n);
    for (int i = 0; i < n; ++i) {
        parent[i] = i;
    }
    for (auto const& edge : edges) {
        int n1 = edge.first;
        int n2 = edge.second;
        while (n1 != parent[n1]) n1 = parent[n1];
        while (n2 != parent[n2]) n2 = parent[n2];
        if (n1 == n2) return false;
        parent[n1] = n2;
    }
    return edges.size() == n - 1;
}