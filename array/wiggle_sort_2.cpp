//
// Created by Xingyuan Wang on 3/19/17.
//

/*
    Given an unsorted array nums, reorder it such that nums[0] < nums[1] > nums[2] < nums[3]....

    Example:
    (1) Given nums = [1, 5, 1, 1, 6, 4], one possible answer is [1, 4, 1, 5, 1, 6].
    (2) Given nums = [1, 3, 2, 2, 3, 1], one possible answer is [2, 3, 1, 3, 1, 2].

    Note:
    You may assume all input has valid answer.

    Follow Up:
    Can you do it in O(n) time and/or in-place with O(1) extra space?
 */

#include "Array.h"

void wiggleSort(vector<int>& nums) {
    // nth_element is a partial sorting algorithm that rearranges
    // elements in [first, last) such that:
    // The element pointed at by nth is changed to whatever element
    // would occur in that position if [first, last) was sorted.
    // All of the elements before this new nth element are less than
    // or equal to the elements after the new nth element.
    if (nums.empty()) return;
    int n = nums.size();

    // Step 1: Find the median
    auto nth = next(nums.begin(), n / 2);
    nth_element(nums.begin(), nth, nums.end());
    int median = *nth;

    // Step 2: Tripartie partition within O(n)-time & O(1)-space. Color Sorting
    auto m = [n](int idx) { return (2 * idx + 1) % (n | 1); };
    int left = 0, right = n - 1;
    int i = 0;
    while (i <= right) {
        if (nums[m(i)] > median) {
            swap(nums[m(i)], nums[m(left)]);
            ++left,
                    ++i;
        } else if (nums[m(i)] < median) {
            swap(nums[m(i)], nums[m(right)]);
            --right;
        } else {
            ++i;
        }
    }
}


// time: O(n)
// space: O(1)
