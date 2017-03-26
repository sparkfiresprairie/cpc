//
// Created by Xingyuan Wang on 3/25/17.
//

/*
    Implement pow(x, n).
 */

#include "Math.h"

double myPow(double x, int n) {
    if (n == 0) return 1;
    if (n == std::numeric_limits<int>::min()) {
        n /= 2;
        x *= x;
    }
    if (n < 0) {
        n = -n;
        x = 1 / x;
    }
    if (n % 2 == 0) return myPow(x * x, n / 2);
    else return x * myPow(x * x, n / 2);
}

// time: O(logn)
// space: O(logn)