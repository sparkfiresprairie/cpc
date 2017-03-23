//
// Created by Xingyuan Wang on 3/23/17.
//

/*
    Given a non-empty 2D matrix matrix and an integer k, find the max sum of a
    rectangle in the matrix such that its sum is no larger than k.

    Example:
    Given matrix = [
      [1,  0, 1],
      [0, -2, 3]
    ]
    k = 2
    The answer is 2. Because the sum of rectangle [[0, 1], [-2, 3]] is 2 and 2
    is the max number no larger than k (k = 2).

    Note:
    The rectangle inside the matrix must have an area > 0.
    What if the number of rows is much larger than the number of columns?
 */

#include "DynamicProgramming.h"

int maxSumSubarray(vector<int> &nums, int k) {
    set<int> sumset;
    sumset.insert(0);
    int best = std::numeric_limits<int>::min(), sum = 0;
    for (int i = 0; i < nums.size(); ++i) {
        sum += nums[i];
        auto sit = sumset.lower_bound(sum - k);
        if (sit != sumset.end()) best = max(best, sum - *sit);
        sumset.insert(sum);
    }
    return best;
}

int maxSumSubmatrix(vector<vector<int>> &matrix, int k) {
    if (matrix.empty() || matrix[0].empty()) return 0;
    int m = matrix.size(), n = matrix[0].size();
    int max_sum = std::numeric_limits<int>::min();
    for (int i = 0; i < n; ++i) {
        vector<int> tmp(m, 0);
        for (int j = i; j < n; ++j) {
            for (int r = 0; r < m; ++r) {
                tmp[r] += matrix[r][j];
            }
            int t = maxSumSubarray(tmp, k);
            max_sum = max(max_sum, t);
        }
    }
    return max_sum;
}

// time: O(n^2 * mlogm)
// space: O(m)


