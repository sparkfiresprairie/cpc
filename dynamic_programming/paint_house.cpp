//
// Created by Xingyuan Wang on 3/7/17.
//

/*
    There are a row of n houses, each house can be painted with one of the three colors:
    red, blue or green. The cost of painting each house with a certain color is different.
    You have to paint all the houses such that no two adjacent houses have the same color.

    The cost of painting each house with a certain color is represented by a n x 3 cost
    matrix. For example, costs[0][0] is the cost of painting house 0 with color red;
    costs[1][2] is the cost of painting house 1 with color green, and so on... Find the
    minimum cost to paint all houses.

    Note:
    All costs are positive integers.
 */

#include "DynamicProgramming.h"

int minCost(vector<vector<int>>& costs) {
    vector<int> pre(3, 0);
    vector<int> cur(3, 0);
    for (int i = 0; i < costs.size(); ++i) {
        cur[0] = min(pre[1], pre[2]) + costs[i][0];
        cur[1] = min(pre[0], pre[2]) + costs[i][1];
        cur[2] = min(pre[0], pre[1]) + costs[i][2];
        pre = cur;
    }
    return min(cur[0], min(cur[1], cur[2]));
}

// time: O(n)
// space: O(1)