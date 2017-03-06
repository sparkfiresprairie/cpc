//
// Created by Xingyuan Wang on 3/5/17.
//

/*
    Given an integer, write a function to determine if it is a power of two.
 */

bool isPowerOfTwo(int n) {
    if(n <= 0) return false;
    return !(n & (n - 1));
}

// time: O(1)
// space: O(1)
