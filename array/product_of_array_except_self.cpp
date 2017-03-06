//
// Created by Xingyuan Wang on 3/5/17.
//

/*
    Given an array of n integers where n > 1, nums, return an array output such that output[i]
    is equal to the product of all the elements of nums except nums[i].

    Solve it without division and in O(n).

    For example, given [1,2,3,4], return [24,12,8,6].

    Follow up:
    Could you solve it with constant space complexity? (Note: The output array does not count
    as extra space for the purpose of space complexity analysis.)
 */

#include "Array.h"

vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n, 1);
    for (int i = 1; i < n; ++i) {
        ans[i] = ans[i - 1] * nums[i - 1];
    }
    int product = 1;
    for (int i = n - 1; i >= 0; --i) {
        ans[i] *= product;
        product *= nums[i];
    }
    return ans;
}

// time: O(n)
// space: O(1) (exclude the output array)

