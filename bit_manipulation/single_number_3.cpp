//
// Created by Xingyuan Wang on 3/7/17.
//

/*
    Given an array of numbers nums, in which exactly two elements appear only once and all the
    other elements appear exactly twice. Find the two elements that appear only once.

    For example:

    Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].

    Note:
    The order of the result is not important. So in the above example, [5, 3] is also correct.
    Your algorithm should run in linear runtime complexity. Could you implement it using only
    constant space complexity?
 */

#include "BitManipulation.h"

vector<int> singleNumber(vector<int>& nums) {
    // Pass 1 :
    // Get the XOR of the two numbers we need to find
    int diff = std::accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
    // Get its last set bit
    diff &= -diff;

    // Pass 2 :
    vector<int> rets = {0, 0}; // this vector stores the two numbers we will return
    for (int num : nums){
        if ((num & diff) == 0) { // the bit is not set
            rets[0] ^= num;
        } else { // the bit is set
            rets[1] ^= num;
        }
    }
    return rets;
}

// time: O(n)
// space: O(1)