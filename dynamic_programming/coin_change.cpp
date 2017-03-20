//
// Created by Xingyuan Wang on 3/19/17.
//

/*
    You are given coins of different denominations and a total amount of money
    amount. Write a function to compute the fewest number of coins that you
    need to make up that amount. If that amount of money cannot be made up by
    any combination of the coins, return -1.

    Example 1:
    coins = [1, 2, 5], amount = 11
    return 3 (11 = 5 + 5 + 1)

    Example 2:
    coins = [2], amount = 3
    return -1.

    Note:
    You may assume that you have an infinite number of each kind of coin.
 */

#include "DynamicProgramming.h"

int coinChange(vector<int> &coins, int amount) {
    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i <= amount; ++i) {
        for (int j = 0; j < coins.size(); ++j) {
            int remains = i - coins[j];
            if (remains < 0 || dp[remains] == -1) continue;
            dp[i] = min(dp[remains] + 1, dp[i]);
        }
        if (dp[i] == INT_MAX) dp[i] = -1;
    }
    return dp[amount];
}

// time: O(amount * coins.size())
// space: O(amount)