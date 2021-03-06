//
// Created by Xingyuan Wang on 3/7/17.
//


/*
    Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.

    For example:

    Given num = 38, the process is like: 3 + 8 = 11, 1 + 1 = 2. Since 2 has only one digit, return it.

    Follow up:
    Could you do it without any loop/recursion in O(1) runtime?

    Hint:

    A naive implementation of the above process is trivial. Could you come up with other methods?
    What are all the possible results?
    How do they occur, periodically or randomly?
    You may find this Wikipedia article useful.
 */

#include "Math.h"

int addDigits(int num) {
    // For base b (decimal case b = 10), the digit root of an integer is:
    // dr(n) = 0 if n == 0
    // dr(n) = (b-1) if n != 0 and n % (b-1) == 0
    // dr(n) = n mod (b-1) if n % (b-1) != 0
    // or
    // dr(n) = 1 + (n - 1) % 9

    return 1 + (num - 1) % 9;
}

// time, space: O(1)