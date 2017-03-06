//
// Created by Xingyuan Wang on 3/5/17.
//

/*
    Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.
    The algorithm should run in linear time and in O(1) space.
 */

#include "Array.h"

vector<int> majorityElement(vector<int>& nums) {
    int candidate1 = 0;
    int candidate2 = 1;
    int count1 = 0;
    int count2 = 0;
    for (auto num : nums) {
        if (num == candidate1) {
            ++count1;
        } else if (num == candidate2) {
            ++count2;
        } else if (count1 == 0) {
            candidate1 = num;
            count1 = 1;
        } else if (count2 == 0) {
            candidate2 = num;
            count2 = 1;
        } else {
            --count1;
            --count2;
        }
    }
    count1 = 0;
    count2 = 0;
    for (auto num : nums) {
        if (num == candidate1) ++count1;
        else if (num == candidate2) ++count2;
    }
    vector<int> ans;
    if (count1 > nums.size() / 3) ans.push_back(candidate1);
    if (count2 > nums.size() / 3) ans.push_back(candidate2);
    return ans;
}

// time: O(n)
// space: O(1)