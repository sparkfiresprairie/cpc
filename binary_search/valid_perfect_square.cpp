//
// Created by Xingyuan Wang on 3/21/17.
//

/*
    Given a positive integer num, write a function which returns True if num is
    a perfect square else False.

    Note: Do not use any built-in library function such as sqrt.

    Example 1:

    Input: 16
    Returns: True
    Example 2:

    Input: 14
    Returns: False

 */

bool isPerfectSquare(int num) {
    long long low = 0, high = num;
    while (low <= high) {
        long long mid = low + (high - low) / 2;
        if (mid * mid == num) return true;
        else if (mid * mid < num) low = mid + 1;
        else high = mid - 1;
    }
    return false;
}

// time: O(log num)
// space: O(1)