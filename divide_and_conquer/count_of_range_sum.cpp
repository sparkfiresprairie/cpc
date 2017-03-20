//
// Created by Xingyuan Wang on 3/19/17.
//

/*
    Given an integer array nums, return the number of range sums that lie in
    [lower, upper] inclusive.
    Range sum S(i, j) is defined as the sum of the elements in nums between
    indices i and j (i ≤ j), inclusive.

    Note:
    A naive algorithm of O(n2) is trivial. You MUST do better than that.

    Example:
    Given nums = [-2, 5, -1], lower = -2, upper = 2,
    Return 3.
    The three ranges are : [0, 0], [2, 2], [0, 2] and their respective sums
    are: -2, -1, 2.
 */

#include "DivideAndConquer.h"

// 在[b, e)区间里有多少i, j满足i < j使得 lower <= sums[j] - sums[i] <= upper
int count_with_merge_sort(vector<long>& sums, int b, int e, int lower, int upper) {
    int n = e - b;
    if (n <= 1) return 0;   // if e - b == 1, only 1 elements, you can not find two elements i, j
    int mid = b + n / 2;
    int count = count_with_merge_sort(sums, b, mid, lower, upper) + count_with_merge_sort(sums, mid, e, lower, upper);
    vector<long> tmp;
    // iterate through the left half with index i.
    // For each i, we need to find two indices k and j in the right half where
    // j is the first index satisfy sums[j] - sums[i] > upper and
    // k is the first index satisfy sums[k] - sums[i] >= lower.
    int i = b, k = mid, j = mid;
    int t = mid;
    while (i < mid) {
        while (k < e && sums[k] - sums[i] < lower) ++k;
        while (j < e && sums[j] - sums[i] <= upper) ++j;
        while (t < e && sums[t] < sums[i]) tmp.push_back(sums[t++]);
        tmp.push_back(sums[i++]);
        count += j - k;
    }
    for (int i = 0; i < tmp.size(); ++i) {
        sums[b + i] = tmp[i];
    }
    return count;
}

int countRangeSum(vector<int>& nums, int lower, int upper) {
    int n = nums.size();
    vector<long> sums(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        sums[i + 1] = nums[i] + sums[i];
    }
    return count_with_merge_sort(sums, 0, n + 1, lower, upper);
}

// time: O(nlogn)
// space: O(n)