//
// Created by Xingyuan Wang on 3/28/17.
//

/*
    Suppose an array sorted in ascending order is rotated at some pivot unknown
    to you beforehand.

    (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

    You are given a target value to search. If found in the array return its
    index, otherwise return -1.

    You may assume no duplicate exists in the array.
 */

#include "BinarySearch.h"

int search(vector<int>& nums, int target) {
    int n = nums.size();
    long low = 0, high = n - 1;
    while (low < high) {
        if (nums[low] < nums[high]) break;
        int mid = low + (high - low) / 2;
        if (nums[mid] >= nums[low]) low = mid + 1;
        else high = mid;
    }
    high = low + n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid % n] == target) return mid % n;
        else if (nums[mid % n] > target) high = mid - 1;
        else low = mid + 1;
    }
    return -1;
}

// time: O(logn)
// space: O(1)