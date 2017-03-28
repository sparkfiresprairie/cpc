//
// Created by Xingyuan Wang on 3/28/17.
//

/*
    Given an integer array with all positive numbers and no duplicates, find the
    number of possible combinations that add up to a positive integer target.

    Example:

    nums = [1, 2, 3]
    target = 4

    The possible combination ways are:
    (1, 1, 1, 1)
    (1, 1, 2)
    (1, 2, 1)
    (1, 3)
    (2, 1, 1)
    (2, 2)
    (3, 1)

    Note that different sequences are counted as different combinations.

    Therefore the output is 7.
    Follow up:
    What if negative numbers are allowed in the given array?
    How does it change the problem?
    What limitation we need to add to the question to allow negative numbers?
 */

#include "DynamicProgramming.h"

int combinationSum4(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    vector<int> dp(target + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= target; ++i) {
        int count = 0;
        for (int j = 0; j < nums.size() && nums[j] <= i; ++j) {
            count += dp[i - nums[j]];
        }
        dp[i] = count;
    }
    return dp[target];
}

// time: O(max(target*n, nlogn))
// space: O(target)