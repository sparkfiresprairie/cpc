//
// Created by Xingyuan Wang on 3/20/17.
//

/*
    Given an unsorted array return whether an increasing subsequence of length 3
    exists or not in the array.

    Formally the function should:
    Return true if there exists i, j, k
    such that arr[i] < arr[j] < arr[k] given 0 ≤ i < j < k ≤ n-1 else return false.
    Your algorithm should run in O(n) time complexity and O(1) space complexity.

    Examples:
    Given [1, 2, 3, 4, 5],
    return true.

    Given [5, 4, 3, 2, 1],
    return false.
 */

#include "Array.h"

bool increasingTriplet(vector<int>& nums) {
    int c1 = std::numeric_limits<int>::max();
    int c2 = std::numeric_limits<int>::max();
    for (auto x : nums) {
        if (x <= c1) {
            c1 = x;
        } else if (x <= c2) {
            c2 = x;
        } else {
            return true;
        }
    }
    return false;
}

// time: O(n)
// space: O(1)
