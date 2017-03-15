//
// Created by Xingyuan Wang on 3/14/17.
//

/*
    Given an integer array nums, find the sum of the elements between indices
    i and j (i ≤ j), inclusive.

    Example:
    Given nums = [-2, 0, 3, -5, 2, -1]

    sumRange(0, 2) -> 1
    sumRange(2, 5) -> -1
    sumRange(0, 5) -> -3
    Note:
    You may assume that the array does not change.
    There are many calls to sumRange function.
 */

#include "Design.h"

class NumArray {
private:
    vector<int> prefix_sum;
public:
    NumArray(vector<int> nums) : prefix_sum(nums.size() + 1, 0) {
        for (int i = 0; i < nums.size(); ++i) {
            prefix_sum[i + 1] = prefix_sum[i] + nums[i];
        }
    }

    int sumRange(int i, int j) {
        return prefix_sum[j + 1] - prefix_sum[i];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */

// time: ctor - O(n), sumRange - O(1)
// space: O(n)