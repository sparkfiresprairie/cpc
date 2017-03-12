//
// Created by Xingyuan Wang on 3/11/17.
//

/*
    A group of two or more people wants to meet and minimize the total travel distance.
    You are given a 2D grid of values 0 or 1, where each 1 marks the home of someone in
    the group. The distance is calculated using Manhattan Distance, where distance
    (p1, p2) = |p2.x - p1.x| + |p2.y - p1.y|.

    For example, given three people living at (0,0), (0,4), and (2,2):

    1 - 0 - 0 - 0 - 1
    |   |   |   |   |
    0 - 0 - 0 - 0 - 0
    |   |   |   |   |
    0 - 0 - 1 - 0 - 0
    The point (0,2) is an ideal meeting point, as the total travel distance of 2+2+2=6
    is minimal. So return 6.

    Hint:

    Try to solve it in one dimension first. How can this solution apply to the two
    dimension case?
 */

#include "Math.h"

// http://math.stackexchange.com/questions/113270/the-median-minimizes-the-sum-of-absolute-deviations

int minDistance1D(vector<int> const& mp) {
    if (mp.empty()) return 0;
    int i = 0, j = mp.size() - 1;
    int d = 0, left = mp[0], right = mp.back();
    while (i < j) {
        if (left < right) {
            ++i;
            d += left;
            left += mp[i];
        } else {
            --j;
            d += right;
            right += mp[j];
        }
    }
    return d;
}

int minTotalDistance(vector<vector<int>>& grid) {
    if (grid.empty() || grid[0].empty()) return 0;
    int m = grid.size(), n = grid[0].size();
    vector<int> mp_m(m, 0);
    vector<int> mp_n(n, 0);
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == 1) {
                ++mp_m[i];
                ++mp_n[j];
            }
        }
    }

    return minDistance1D(mp_m) + minDistance1D(mp_n);
}

// time: O(mn)
// space: O(m + n)

//int minTotalDistance(vector<vector<int>>& grid) {
//    if (grid.empty() || grid[0].empty()) return 0;
//    int m = grid.size(), n = grid[0].size();
//    vector<int> points_m;
//    vector<int> points_n;
//    for (int i = 0; i < m; ++i) {
//        for (int j = 0; j < n; ++j) {
//            if (grid[i][j] == 1) {
//                points_m.push_back(i);
//            }
//        }
//    }
//
//    for (int j = 0; j < n; ++j) {
//        for (int i = 0; i < m; ++i) {
//            if (grid[i][j] == 1) {
//                points_n.push_back(j);
//            }
//        }
//    }
//
//    return minDistance1D(points_m) + minDistance1D(points_n);
//}
//
//// http://math.stackexchange.com/questions/113270/the-median-minimizes-the-sum-of-absolute-deviations
//int minDistance1D(vector<int> const& points) {
//    int i = 0, j = points.size() - 1;
//    int sum = 0;
//    while (i < j) {
//        sum += points[j--] - points[i++];
//    }
//    return sum;
//}

// time: O(mn)
// space: O(mn)
