//
// Created by Xingyuan Wang on 3/5/17.
//

/*
    Given an integer, write a function to determine if it is a power of three.
 */

#include "Math.h"

bool isPowerOfThree(int n) {
    int maxPowerOfThree = (int)pow(3, (int)(log(0x7fffffff) / log(3)));
    return n > 0 && maxPowerOfThree % n == 0;
}

// time: O(1)
// space: O(1)