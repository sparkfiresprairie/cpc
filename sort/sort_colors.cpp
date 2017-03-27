//
// Created by Xingyuan Wang on 3/27/17.
//

/*
    Given an array with n objects colored red, white or blue, sort them so that
    objects of the same color are adjacent, with the colors in the order red,
    white and blue.

    Here, we will use the integers 0, 1, and 2 to represent the color red, white,
    and blue respectively.

    Note:
    You are not suppose to use the library's sort function for this problem.

    click to show follow up.

    Follow up:
    A rather straight forward solution is a two-pass algorithm using counting sort.
    First, iterate the array counting number of 0's, 1's, and 2's, then overwrite
    array with total number of 0's, then 1's and followed by 2's.

    Could you come up with an one-pass algorithm using only constant space?
 */

#include "Sort.h"

void sortColors(vector<int>& nums) {
    int i = 0;
    int j = nums.size() - 1;
    int k = 0;
    while (k <= j) {
        if (nums[k] == 0) {
            swap(nums[k], nums[i++]);
            ++k;
        } else if (nums[k] == 2) {
            swap(nums[k], nums[j--]);
        } else {
            ++k;
        }
    }
}

// time: O(n)
// space: O(1)