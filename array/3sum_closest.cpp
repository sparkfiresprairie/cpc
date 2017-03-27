//
// Created by Xingyuan Wang on 3/26/17.
//

/*
    Given an array S of n integers, find three integers in S such that the sum is
    closest to a given number, target. Return the sum of the three integers. You
    may assume that each input would have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 */

#include "Array.h"

int threeSumClosest(vector<int>& nums, int target) {
    if (nums.size() < 3) return 0;
    int closest = nums[0] + nums[1] + nums[2];
    sort(nums.begin(), nums.end());
    for (int i = 0; i + 2 < nums.size(); ++i) {
        int j = i + 1, k = nums.size() - 1;
        while (j < k) {
            int cur = nums[i] + nums[j] + nums[k];
            if (cur == target) return cur;
            if (abs(target - cur) < abs(target - closest)) closest = cur;
            if (cur > target) --k;
            else ++j;
        }
    }
    return closest;
}

// time: O(n^2)
// space: O(1)