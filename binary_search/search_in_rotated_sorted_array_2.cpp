//
// Created by Xingyuan Wang on 3/28/17.
//

/*
    Follow up for "Search in Rotated Sorted Array":
    What if duplicates are allowed?

    Would this affect the run-time complexity? How and why?
    Suppose an array sorted in ascending order is rotated at some pivot unknown to
    you beforehand.

    (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

    Write a function to determine if a given target is in the array.

    The array may contain duplicates.
 */

#include "BinarySearch.h"

bool search(vector<int>& nums, int target) {
    int n = nums.size();
    long low = 0, high = n - 1;
    while (low < high) {
        if (nums[low] < nums[high]) break;
        int mid = low + (high - low) / 2;
        if (nums[mid] < nums[high]) high = mid;
        else if (nums[mid] > nums[high]) low = mid + 1;
        else {
            if (nums[high - 1] > nums[high]) {
                low = high;
                break;
            }
            --high;
        }
    }
    high = low + n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid % n] == target) return true;
        else if (nums[mid % n] > target) high = mid - 1;
        else low = mid + 1;
    }
    return false;
}

// time: worst O(n)
// space: O(1)