//
// Created by Xingyuan Wang on 3/17/17.
//

/*
    Given an array nums and a target value k, find the maximum length of a subarray
    that sums to k. If there isn't one, return 0 instead.

    Note:
    The sum of the entire nums array is guaranteed to fit within the 32-bit signed
    integer range.

    Example 1:
    Given nums = [1, -1, 5, -2, 3], k = 3,
    return 4. (because the subarray [1, -1, 5, -2] sums to 3 and is the longest)

    Example 2:
    Given nums = [-2, -1, 2, 1], k = 1,
    return 2. (because the subarray [-1, 2] sums to 1 and is the longest)

    Follow Up:
    Can you do it in O(n) time?
 */

#include "HashTable.h"

int maxSubArrayLen(vector<int>& nums, int k) {
    unordered_map<int, int> map;
    map.insert({0, -1});
    int ans = 0;
    int sum = 0;
    for (int i = 0; i < nums.size(); ++i) {
        sum += nums[i];
        if (map.find(sum - k) != map.end()) {
            ans = max(ans, i - map[sum - k]);
        }
        if (map.find(sum) == map.end()) {
            map.insert({sum, i});
        }
    }
    return ans;
}
