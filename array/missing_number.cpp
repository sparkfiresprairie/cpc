//
// Created by Xingyuan Wang on 3/8/17.
//

/*
    Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is
    missing from the array.

    For example,
    Given nums = [0, 1, 3] return 2.

    Note:
    Your algorithm should run in linear runtime complexity. Could you implement it using only
    constant extra space complexity?
 */

#include "Array.h"

int missingNumber(vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
        if (nums[i] == i) continue;
        while (nums[i] < n && nums[nums[i]] != nums[i]) {
            swap(nums[i], nums[nums[i]]);
        }
    }
    for (int i = 0; i < n; ++i) {
        if (nums[i] != i) return i;
    }
    return n;
}

// time: O(n)
// space: O(1)

//int missingNumber(vector<int>& nums) {
//    int result = nums.size();
//    int i = 0;
//    for (auto num : nums) {
//        result ^= num;
//        result ^= i;
//        ++i;
//    }
//    return result;
//}

//int missingNumber(vector<int>& nums) {
//    int n = nums.size();
//    int sum = 0;
//    for (int i = 0; i < n; i += 1) {
//        sum += nums[i];
//    }
//    return n * (n + 1) / 2 - sum;
//}