//
// Created by Xingyuan Wang on 2/26/17.
//

/*
    Given an array of integers, find if the array contains any duplicates.
    Your function should return true if any value appears at least twice
    in the array, and it should return false if every element is distinct.
 */

#include "HashTable.h"

bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> st;
    for (auto num : nums) {
        if (st.find(num) != st.end()) return true;
        st.insert(num);
    }
    return false;
}

// time: O(n)
// space: O(min(n, k))


