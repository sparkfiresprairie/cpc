//
// Created by Xingyuan Wang on 3/16/17.
//

/*
    Given n balloons, indexed from 0 to n-1. Each balloon is painted with a number on
    it represented by array nums. You are asked to burst all the balloons. If the you
    burst balloon i you will get nums[left] * nums[i] * nums[right] coins. Here left
    and right are adjacent indices of i. After the burst, the left and right then
    becomes adjacent.

    Find the maximum coins you can collect by bursting the balloons wisely.

    Note:
    (1) You may imagine nums[-1] = nums[n] = 1. They are not real therefore you can
    not burst them.
    (2) 0 ≤ n ≤ 500, 0 ≤ nums[i] ≤ 100

    Example:

    Given [3, 1, 5, 8]

    Return 167

        nums = [3,1,5,8] --> [3,5,8] -->   [3,8]   -->  [8]  --> []
       coins =  3*1*5      +  3*5*8    +  1*3*8      + 1*8*1   = 167
 */

#include "DynamicProgramming.h"

int maxCoins(vector<int>& nums) {
    int n = nums.size();
    nums.insert(nums.begin(), 1);
    nums.insert(nums.end(), 1);

    // dp[i][j] is the maximum # of coins that can be obtained
    // by poping balloons only in the range [i, j];
    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
    // build up from shorter ranges to longer ranges
    for (int len = 1; len <= n; ++len) {
        for (int start = 1; start <= n - len + 1; ++start) {
            int end = start + len - 1;
            int best_coins = 0;
            for (int final = start; final <= end; ++final) {
                int coins = dp[start][final - 1] + dp[final + 1][end];
                coins += nums[start - 1] * nums[final] * nums[end + 1];
                best_coins = max(best_coins, coins);
            }
            dp[start][end] = best_coins;
        }
    }
    return dp[1][n];
}

// time: O(n^3)
// space: O(n^2)