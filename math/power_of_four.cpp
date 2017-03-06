//
// Created by Xingyuan Wang on 3/5/17.
//

/*
    Given an integer (signed 32 bits), write a function to check whether it is a power of 4.

    Example:
    Given num = 16, return true. Given num = 5, return false.

    Follow up: Could you solve it without loops/recursion?
 */

bool isPowerOfFour(int num) {
    return num > 0 && (num & (num - 1)) == 0 && (num - 1) % 3 == 0;
}

// time: O(1)
// space: O(1)

// Prove:
// (by induction) 4^(n+1) - 1 = 44^n -1 = 34^n + 4^n-1. The first is divided by 3, the second is proven by induction hypothesis
// Any number passes "n^(n-1)==0" must be powers of 2. All numbers above could be further categorized to 2 class.
// A: all numbers that are 2^(2k+1) and B: all numbers that 2^(2k).
// We could show that 2^(2k+1)-1 could not pass the test of (n-1)%3==0. (by induction) So all A are ruled out,
// leaving only B, which is power of 4.