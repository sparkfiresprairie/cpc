//
// Created by Xingyuan Wang on 3/8/17.
//

/*
    You are a product manager and currently leading a team to develop a new product. Unfortunately,
    the latest version of your product fails the quality check. Since each version is developed
    based on the previous version, all the versions after a bad version are also bad.

    Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which
    causes all the following ones to be bad.

    You are given an API bool isBadVersion(version) which will return whether version is bad.
    Implement a function to find the first bad version. You should minimize the number of calls to
    the API.
 */

#include "BinarySearch.h"

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

int firstBadVersion(int n) {
    int low = 1;
    int high = n;
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (isBadVersion(mid)) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    return low;
}

// time: O(log n)
// space: O(1)