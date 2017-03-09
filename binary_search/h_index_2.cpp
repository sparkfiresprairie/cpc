//
// Created by Xingyuan Wang on 3/8/17.
//

/*
    Follow up for H-Index: What if the citations array is sorted in ascending order?
    Could you optimize your algorithm?

    Hint:

    Expected runtime complexity is in O(log n) and the input is sorted.
 */

#include "BinarySearch.h"

int hIndex(vector<int>& citations) {
    if (citations.empty()) return 0;
    int sz = citations.size();
    int left = 0;
    int right = sz - 1;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (citations[mid] >= sz - mid) right = mid;
        else left = mid + 1;
    }
    return min(sz - left, citations[left]);
}

// time: O(log n)
// space: O(1)