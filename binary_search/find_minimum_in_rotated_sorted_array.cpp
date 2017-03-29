//
// Created by Xingyuan Wang on 3/28/17.
//

/*
    Suppose an array sorted in ascending order is rotated at some pivot
    unknown to you beforehand.

    (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

    Find the minimum element.

    You may assume no duplicate exists in the array.
 */

#include "BinarySearch.h"

int findMin(vector<int>& nums) {
    int n = nums.size();
    int low = 0, high = n - 1;

    while (low < high) {
        if (nums[low] < nums[high]) break;  //this invariant is very important to judge when == case
        int mid = low + (high - low) / 2;
        if (nums[mid] >= nums[low]) low = mid + 1;
        else high = mid;
    }

    return nums[low];
}
// time: O(logn)
// space: O(1)
