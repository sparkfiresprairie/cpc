//
// Created by Xingyuan Wang on 3/18/17.
//

/*
    You are given an integer array nums and you have to return a new counts array.
    The counts array has the property where counts[i] is the number of smaller
    elements to the right of nums[i].

    Example:

    Given nums = [5, 2, 6, 1]

    To the right of 5 there are 2 smaller elements (2 and 1).
    To the right of 2 there is only 1 smaller element (1).
    To the right of 6 there is 1 smaller element (1).
    To the right of 1 there is 0 smaller element.
    Return the array [2, 1, 1, 0].
 */

#include "DivideAndConquer.h"

// The basic idea is to do merge sort to nums[].
// To record the result, we need to keep the index
// of each number in the original array. So instead
// of sort the number in nums, we sort the indexes of each number.
// [b,e)
void merge_count_smaller(vector<int>& indices, int b, int e, vector<int>& ans, vector<int> const& nums) {
    int n = e - b;
    if (n > 1) {
        int mid = b + n / 2;
        merge_count_smaller(indices, b, mid, ans, nums);
        merge_count_smaller(indices, mid, e, ans, nums);
        vector<int> tmp(n, 0);
        int i = b;
        int j = mid;
        int idx = 0;
        int inv_count = 0;
        while (i < mid || j < e) {
            if (j == e || i < mid && nums[indices[i]] <= nums[indices[j]]) {
                tmp[idx++] = indices[i];
                ans[indices[i]] += inv_count;
                ++i;
            } else {
                tmp[idx++] = indices[j];
                ++inv_count;
                ++j;
            }
        }
        for (int i = 0; i < tmp.size(); ++i) {
            indices[b + i] = tmp[i];
        }
    }
}

vector<int> countSmaller(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n, 0);
    vector<int> indices(n, 0);
    iota(indices.begin(), indices.end(), 0);    // 0,1,2,..., n - 1
    merge_count_smaller(indices, 0, n, ans, nums);
    return ans;
}

// time: O(nlogn)
// space: O(n)