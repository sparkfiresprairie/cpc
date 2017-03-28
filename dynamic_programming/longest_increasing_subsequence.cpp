//
// Created by Xingyuan Wang on 3/14/17.
//

/*
    Given an unsorted array of integers, find the length of longest increasing subsequence.

    For example,
    Given [10, 9, 2, 5, 3, 7, 101, 18],
    The longest increasing subsequence is [2, 3, 7, 101], therefore the length is 4. Note
    that there may be more than one LIS combination, it is only necessary for you to return
    the length.

    Your algorithm should run in O(n2) complexity.

    Follow up: Could you improve it to O(n log n) time complexity?
 */

#include "DynamicProgramming.h"

int lengthOfLIS(vector<int>& nums) {
    if (nums.empty()) return 0;
    vector<int> dp(nums.size(), 1);
    int longest = 1;
    for (int i = 1; i < nums.size(); ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[j] < nums[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        longest = max(longest, dp[i]);
    }
    return longest;
}

// time: O(n^2)
// space: O(n)

// http://www.geeksforgeeks.org/longest-monotonically-increasing-subsequence-size-n-log-n/

//int lengthOfLIS(vector<int>& nums) {
//    if (nums.empty()) return 0;
//
//    vector<int> tails(nums.size(), 0);
//    int length = 1;     // always points empty slot in tail;
//    tails[0] = nums[0];
//    // Our strategy determined by the following conditions,
//    // 1. If A[i] is smallest among all end candidates of active lists,
//    // we will start new active list of length 1.
//    // 2. If A[i] is largest among all end candidates of active lists,
//    // we will clone the largest active list, and extend it by A[i].
//    // 3. If A[i] is in between, we will find a list with largest end
//    // element that is smaller than A[i]. Clone and extend this list by
//    // A[i]. We will discard all other lists of same length as that of
//    // this modified list.
//    for (int i = 1; i < nums.size(); ++i) {
//        if (nums[i] < tails[0]) {   // new smallest value
//            tails[0] = nums[i];
//        } else if (nums[i] > tails[length - 1]) {   // nums[i] extends largest subsequence
//            tails[length++] = nums[i];
//        } else {
//            // nums[i] will become end candidate of an existing subsequence
//            // Throw away larger elements in all LIS, to make room for upcoming
//            // grater elements than nums[i]
//            // (and also, nums[i] would have already appeared in one of LIS,
//            // identify the location and replace it)
//            tails[find_smallest_larger(tails, 0, length - 1, nums[i])] = nums[i];
//        }
//    }
//
//    return length;
//}
//
//int find_smallest_larger(vector<int> const& tails, int low, int high, int key) {
//    while (low < high) {
//        int mid = low + (high - low) / 2;
//        if (tails[mid] > key) {
//            high = mid;
//        } else if (tails[mid] < key) {
//            low = mid + 1;
//        } else {
//            return mid;
//        }
//    }
//    return low;
//}

// time: O(nlogn)
// space: O(n)