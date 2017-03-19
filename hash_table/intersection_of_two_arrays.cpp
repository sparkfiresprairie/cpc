//
// Created by Xingyuan Wang on 3/18/17.
//

/*
    Given two arrays, write a function to compute their intersection.

    Example:
    Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].

    Note:
    Each element in the result must be unique.
    The result can be in any order.
 */

#include "HashTable.h"

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    vector<int> intersections;
    unordered_set<int> st1(nums1.begin(), nums1.end());
    unordered_set<int> st2(nums2.begin(), nums2.end());
    for (auto const& i : st1) {
        if (st2.find(i) != st2.end()) intersections.push_back(i);
    }
    return intersections;
}

// time: O(m + n)
// space: O(m + n)


//vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
//    vector<int> intersections;
//    sort(nums1.begin(), nums1.end());
//    sort(nums2.begin(), nums2.end());
//    int i = 0, j = 0;
//    while (i < nums1.size() && j < nums2.size()) {
//        if (nums1[i] < nums2[j]) ++i;
//        else if (nums1[i] > nums2[j]) ++j;
//        else {
//            intersections.push_back(nums1[i]);
//            ++i;
//            ++j;
//            while (i < nums1.size() && nums1[i] == nums1[i - 1]) ++i;
//            while (j < nums2.size() && nums2[j] == nums2[j - 1]) ++j;
//        }
//    }
//    return intersections;
//}
//
//// time: O (mlogm + nlogn)
//// space: O(1)