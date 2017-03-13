//
// Created by Xingyuan Wang on 3/13/17.
//

/*
    Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0?
    Find all unique triplets in the array which gives the sum of zero.

    Note: The solution set must not contain duplicate triplets.

    For example, given array S = [-1, 0, 1, 2, -1, -4],

    A solution set is:
    [
      [-1, 0, 1],
      [-1, -1, 2]
    ]
 */

#include "Array.h"

vector<vector<int>> threeSum(vector<int>& nums){
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());

    for (int i = 0; i + 2 < nums.size() && nums[i] <= 0; ++i) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        int target = -nums[i];
        int j = i + 1;
        int k = nums.size() - 1;
        while (j < k) {
            if (nums[j] + nums[k] > target) {
                --k;
            } else if (nums[j] + nums[k] < target) {
                ++j;
            } else {
                ans.push_back(vector<int>{nums[i], nums[j], nums[k]});
                ++j;
                --k;
                while (j < k && nums[j] == nums[j - 1]) ++j;
                while (j < k && nums[k] == nums[k + 1]) --k;
            }
        }
    }
    return ans;
}

// time: O(n^2)
// space: O(1)