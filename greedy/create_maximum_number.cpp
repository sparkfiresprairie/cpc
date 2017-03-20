//
// Created by Xingyuan Wang on 3/19/17.
//

/*
    Given two arrays of length m and n with digits 0-9 representing two numbers.
    Create the maximum number of length k <= m + n from digits of the two. The
    relative order of the digits from the same array must be preserved. Return
    an array of the k digits. You should try to optimize your time and space complexity.

    Example 1:
    nums1 = [3, 4, 6, 5]
    nums2 = [9, 1, 2, 5, 8, 3]
    k = 5
    return [9, 8, 6, 5, 3]

    Example 2:
    nums1 = [6, 7]
    nums2 = [6, 0, 4]
    k = 5
    return [6, 7, 6, 0, 4]

    Example 3:
    nums1 = [3, 9]
    nums2 = [8, 9]
    k = 3
    return [9, 8, 9]
 */

#include "Greedy.h"

// Given one array of length n, create the maximum number of length k
vector<int> max_number(vector<int> const& nums, int k) {
    vector<int> stk;
    int n = nums.size();
    int discard = n - k;
    for (int i = 0; i < n; ++i) {
        while (!stk.empty() && stk.back() < nums[i] && discard > 0) {
            stk.pop_back();
            --discard;
        }
        stk.push_back(nums[i]);
    }
    while (stk.size() > k) {
        stk.pop_back();
    }
    return stk;
}

// time: O(nums.size())
// space: O(nums.size())

bool greater(vector<int> const& nums1, int i, vector<int> const& nums2, int j) {
    while (i < nums1.size() && j < nums2.size() && nums1[i] == nums2[j]) {
        ++i;
        ++j;
    }
    return j == nums2.size() || (i < nums1.size() && nums1[i] > nums2[j]);
}

// time: O(nums1.size() + nums2.size()) = O(m + n)
// space: O(1)

vector<int> merge(vector<int> const& nums1, vector<int> const& nums2, int k) {
    vector<int> ans(k, 0);
    for (int i = 0, j = 0, r = 0; r < k; ++r) {
        ans[r] = greater(nums1, i, nums2, j) ? nums1[i++] : nums2[j++];
    }
    return ans;
}
// time: O((m + n)^2)
// space: O(m + n)

vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
    int m = nums1.size(), n = nums2.size();
    vector<int> ans(k, 0);
    for (int i = max(0, k - n); i <= k && i <= m; ++i) {
        vector<int> candidate = merge(max_number(nums1, i), max_number(nums2, k - i), k);
        if (greater(candidate, 0, ans, 0)) ans = candidate;
    }
    return ans;
}

// time: O(k*(m + n)^2)
// space: O(m + n)