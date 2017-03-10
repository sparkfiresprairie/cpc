//
// Created by Xingyuan Wang on 3/9/17.
//

/*
    Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

    For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].

    Note:
    You must do this in-place without making a copy of the array.
    Minimize the total number of operations.
 */

#include "Array.h"

void moveZeroes(vector<int>& nums) {
    int idx = 0;
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] != 0) {
            nums[idx] = nums[i];
            ++idx;
        }
    }
    while (idx < nums.size()) {
        nums[idx] = 0;
        ++idx;
    }
}

// time: O(n)
// space: O(1)

//void moveZeroes(vector<int>& nums) {
//    int idx = 0;
//    for (int i = 0; i < nums.size(); ++i) {
//        if (nums[i] != 0) {
//            swap(nums[idx], nums[i]);
//            ++idx;
//        }
//    }
//}