//
// Created by Xingyuan Wang on 3/16/17.
//

/*
    Say you have an array for which the ith element is the price of a given stock on day i.

    Design an algorithm to find the maximum profit. You may complete at most k transactions.

    Note:
    You may not engage in multiple transactions at the same time (ie, you must sell the stock
    before you buy again).
 */

#include "DynamicProgramming.h"

int maxProfit(int k, vector<int>& prices) {
    int n = prices.size();
    if (n <= 1) return 0;
    if (k > n / 2){ // simple case
        int ans = 0;
        for (int i = 1; i < n; ++i){
            ans += max(prices[i] - prices[i - 1],0);
        }
        return ans;
    }
    vector<int> pre(n, 0);
    vector<int> cur(n, 0);
    for (int i = 1; i <= k; ++i) {
        int temp = INT_MIN;
        for (int j = 1; j < n; ++j) {
            temp = max(temp, pre[j - 1] - prices[j - 1]);
            cur[j] = max(cur[j - 1], prices[j] + temp);
        }
        pre = cur;
    }
    return pre[n - 1];
}