//
// Created by Xingyuan Wang on 3/26/17.
//

/*
    Given an array of n positive integers and a positive integer s, find the minimal
    length of a contiguous subarray of which the sum ≥ s. If there isn't one, return
    0 instead.

    For example, given the array [2,3,1,2,4,3] and s = 7,
    the subarray [4,3] has the minimal length under the problem constraint.

    click to show more practice.

    More practice:
    If you have figured out the O(n) solution, try coding another solution of which
    the time complexity is O(n log n).
 */

#include "Array.h"

int minSubArrayLen(int s, vector<int>& nums) {
    int ans = std::numeric_limits<int>::max();
    int count = 0, sum = 0;
    int i = 0, j = 0;
    while (j < nums.size()) {
        ++count;
        sum += nums[j];
        if (sum >= s) {
            while (i <= j && sum - nums[i] >= s) {
                sum -= nums[i];
                --count;
                ++i;
            }
            ans = min(ans, count);
        }
        ++j;
    }
    return ans == std::numeric_limits<int>::max() ? 0 : ans;
}

// time: O(n)
// space: O(1)