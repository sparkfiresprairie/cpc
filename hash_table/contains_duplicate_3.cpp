//
// Created by Xingyuan Wang on 2/26/17.
//

/*
    Given an array of integers, find out whether there are two distinct indices
    i and j in the array such that the absolute difference between nums[i] and
    nums[j] is at most t and the absolute difference between i and j is at most k.
 */

#include "HashTable.h"

bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    if (k < 1 || t < 0) return false;
    unordered_map<long, long> mp;
    for (int i = 0; i < nums.size(); ++i) {
        if (i > k) {
            long key = ((long) nums[i - k - 1] - INT_MIN) / ((long) t + 1);
            mp.erase(key);
        }
        long remapped_num = (long) nums[i] - INT_MIN;
        long bucket = remapped_num / ((long) t + 1);
        if (mp.find(bucket) != mp.end() ||
            mp.find(bucket - 1) != mp.end() && remapped_num - mp[bucket - 1] <= t ||
            mp.find(bucket + 1) != mp.end() && mp[bucket + 1] - remapped_num <= t)  {
            return true;
        }
        mp.insert({bucket, remapped_num});
    }
    return false;
}

// time: O(n)
// space: O(min(n, k))
