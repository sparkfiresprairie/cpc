//
// Created by Xingyuan Wang on 3/23/17.
//

/*
    Given an array of integers A and an integer k, find a subarray that
    contains the largest sum, subject to a constraint that the sum is
    less than k?
 */

#include "Array.h"

int maximumSubarrayNoLargerThanK (vector<int> const& nums, int k) {
    set<int> sumset;
    sumset.insert(0);
    int best = 0, sum = 0;
    for(int i = 0;i < nums.size(); ++i) {
        sum += nums[i];
        auto sit = sumset.lower_bound(sum - k);
        if (sit != sumset.end()) best = max(best, sum - *sit);
        sumset.insert(sum);
    }
    return best;
}

// time: O(nlogn)
// space: O(n)