//
// Created by Xingyuan Wang on 3/10/17.
//

/*
    You are playing the following Nim Game with your friend: There is a heap of stones on the
    table, each time one of you take turns to remove 1 to 3 stones. The one who removes the
    last stone will be the winner. You will take the first turn to remove the stones.

    Both of you are very clever and have optimal strategies for the game. Write a function to
    determine whether you can win the game given the number of stones in the heap.

    For example, if there are 4 stones in the heap, then you will never win the game: no matter
    1, 2, or 3 stones you remove, the last stone will always be removed by your friend.

    Hint:

    If there are 5 stones in the heap, could you figure out a way to remove the stones such
    that you will always be the winner?
 */

#include "DynamicProgramming.h"

bool canWinNim(int n) {
    if (n == 0) return false;
    if (n > 0 && n <= 3) return true;
    vector<bool> dp(n + 1, false);
    dp[1] = dp[2] = dp[3] = true;
    for (int i = 4; i <= n; ++i) {
        dp[i] = !(dp[i - 1] && dp[i - 2] && dp[i - 3]);
    }
    return dp[n];
}

// time: O(n)
// space: O(n)

//bool canWinNim(int n) {
//    if (n == 0) return false;
//    if (n > 0 && n <= 3) return true;
//    bool n1 = true, n2 = true, n3 = true;
//    for (int i = 4; i <= n; ++i) {
//        bool cur = !(n1 && n2 && n3);
//        n1 = n2;
//        n2 = n3;
//        n3 = cur;
//    }
//    return n3;
//}
//
//// time: O(n)
//// space: O(1)
//
//bool canWinNim(int n) {
//    return n % 4 != 0;
//}
//
//// time: O(1)
//// space: O(1)