//
// Created by Xingyuan Wang on 3/20/17.
//

/*
    Given a non-empty array of integers, return the k most frequent elements.

    For example,
    Given [1,1,1,2,2,3] and k = 2, return [1,2].

    Note:
    You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
    Your algorithm's time complexity must be better than O(n log n), where n
    is the array's size.
 */

#include "HashTable.h"

vector<int> topKFrequent(vector<int>& nums, int k) {
    vector<vector<int>> bucket(nums.size() + 1);
    unordered_map<int, int> mp;
    for (auto num : nums) {
        ++mp[num];
    }
    for (auto const& e : mp) {
        bucket[e.second].push_back(e.first);
    }
    vector<int> top_k;
    for (int i = bucket.size() - 1; i >= 0 && top_k.size() < k; --i) {
        if (!bucket[i].empty()) {
            top_k.insert(top_k.end(), bucket[i].begin(), bucket[i].end());
        }
    }
    return top_k;
}

// time: O(n)
// spae: O(n)
