//
// Created by Xingyuan Wang on 3/16/17.
//

/*
    Say you have an array for which the ith element is the price of a given stock on day i.

    Design an algorithm to find the maximum profit. You may complete at most two transactions.

    Note:
    You may not engage in multiple transactions at the same time (ie, you must sell the stock
    before you buy again).
 */

#include "DynamicProgramming.h"

int maxProfit(vector<int>& prices) {
    // dp[i][j] represents the max profit up until prices[j](Note: NOT ending with prices[j]) using at most i transactions.
    // dp[i][j] = max(dp[i][j - 1], dp[i - 1][k] + price[j] - price[k]) (k in range [0, j - 1])
    //          = max(dp[i][j - 1], price[j] + max(dp[i - 1][k] - price[k]))
    // dp[0][j] = 0; 0 times transation makes 0 profit
    // dp[i][0] = 0; if there is only one price data point you can't make any money no matter how many times you can trade
     int n = prices.size(), num = 2;
     if (n <= 1) return 0;
     vector<vector<int>> dp(num + 1, vector<int>(n, 0));
     for (int i = 1; i <= num; ++i) {
         int temp = INT_MIN;
         for (int j = 1; j < n; ++j) {
             temp = max(temp, dp[i - 1][j - 1] - prices[j - 1]);
             dp[i][j] = max(dp[i][j - 1], prices[j] + temp);
         }
     }
     return dp[num][n - 1];

}

// time: O(num * n)
// space: O(num * n)

//int maxProfit(vector<int>& prices) {
//        int n = prices.size(), num = 2;
//        if (n <= 1) return 0;
//        vector<int> pre(n, 0);
//        vector<int> cur(n, 0);
//        for (int i = 1; i <= num; ++i) {
//            int temp = INT_MIN;
//            for (int j = 1; j < n; ++j) {
//                temp = max(temp, pre[j - 1] - prices[j - 1]);
//                cur[j] = max(cur[j - 1], prices[j] + temp);
//            }
//            pre = cur;
//        }
//        return pre[n - 1];
//};
//
//// time: O(num * n)
//// space: O(n)