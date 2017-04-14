//
// Created by Xingyuan Wang on 4/12/17.
//

/*
    Implement strStr().

    Returns the index of the first occurrence of needle in haystack, or -1 if needle
    is not part of haystack.
 */

#include "String.h"

int strStr(string haystack, string needle) {
    if (needle.empty()) return 0;
    int m = haystack.size();
    int n = needle.size();
    for (int i = 0; i < m - n + 1; ++i) {
        if (haystack[i] != needle[0]) continue;
        int j = 1;
        while(j < needle.size() && haystack[i + j] == needle[j]) ++j;
        if (j == n) return i;
    }
    return -1;
}

// time: O((m - n) * n)
// space: O(1)