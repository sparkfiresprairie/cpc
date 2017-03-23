//
// Created by Xingyuan Wang on 3/17/17.
//

/*
    Given n points on a 2D plane, find if there is such a line parallel to y-axis
    that reflect the given points.

    Example 1:
    Given points = [[1,1],[-1,1]], return true.

    Example 2:
    Given points = [[1,1],[-1,-1]], return false.

    Follow up:
    Could you do better than O(n2)?

    Hint:

    Find the smallest and largest x-value for all points.
    If there is a line then it should be at y = (minX + maxX) / 2.
    For each point, make sure that it has a reflected point in the opposite side.
 */

#include "HashTable.h"

bool isReflected(vector<pair<int, int>>& points) {
    unordered_map<int, unordered_set<int>> hm;
    int min_x = INT_MAX, max_x = INT_MIN;
    for (auto const& point : points) {
        int x = point.first;
        int y = point.second;
        hm[x].insert(y);
        if (x < min_x) min_x = x;
        if (x > max_x) max_x = x;
    }

    int target = max_x + min_x;
    for (auto const& e : hm) {
        int x1 = e.first;
        if (hm.find(target - x1) == hm.end()) return false;
        auto const& y1 = hm[x1];
        auto const& y2 = hm[target - x1];
        for (int y : y1) {
            if (y2.find(y) == y2.end()) return false;
        }
    }
    return true;
}

// time: O(n)
// space: O(n)