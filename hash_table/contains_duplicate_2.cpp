//
// Created by Xingyuan Wang on 2/26/17.
//

#include "HashTable.h"

/*
    Given an array of integers and an integer k, find out whether there are
    two distinct indices i and j in the array such that nums[i] = nums[j]
    and the absolute difference between i and j is at most k.
 */

bool containsNearbyDuplicate(vector<int>& nums, int k) {
    unordered_set<int> st;
    for (int i = 0; i < nums.size(); ++i) {
        if (i > k) st.erase(nums[i - k - 1]);
        if (st.find(nums[i]) != st.end()) return true;
        st.insert(nums[i]);
    }
    return false;
}

// time: O(n)
// space: O(min(n, k))
