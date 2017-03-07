//
// Created by Xingyuan Wang on 3/6/17.
//

/*
    A strobogrammatic number is a number that looks the same when rotated 180 degrees
    (looked at upside down).

    Write a function to determine if a number is strobogrammatic. The number is
    represented as a string.

    For example, the numbers "69", "88", and "818" are all strobogrammatic.
 */

#include "HashTable.h"

bool isStrobogrammatic(string num) {
    unordered_map<char, char> m = {{'6', '9'}, {'9', '6'}, {'0', '0'}, {'1', '1'}, {'8', '8'}};
    int low = 0, high = num.size() - 1;
    while (low <= high) {
        if (m[num[low]] != num[high]) return false;
        ++low;
        --high;
    }
    return true;
}

// time: O(n)
// space: O(1)