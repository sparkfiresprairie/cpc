//
// Created by Xingyuan Wang on 3/20/17.
//

/*
    Given two arrays, write a function to compute their intersection.

    Example:
    Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2, 2].

    Note:
    Each element in the result should appear as many times as it shows in both arrays.
    The result can be in any order.
    Follow up:
    What if the given array is already sorted? How would you optimize your algorithm?
    What if nums1's size is small compared to nums2's size? Which algorithm is better?
    What if elements of nums2 are stored on disk, and the memory is limited such that
    you cannot load all elements into the memory at once?
 */


/*
3. If only nums2 cannot fit in memory, put all elements of nums1 into a HashMap,
   read chunks of array that fit into the memory, and record the intersections.
   If both nums1 and nums2 are so huge that neither fit into the memory, sort
   them individually (external sort), then read 2 elements from each array at
   a time in memory, record intersections.
 */

#include "HashTable.h"

vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> mp;
    vector<int> intersections;
    for (int i = 0; i < nums1.size(); ++i) {
        ++mp[nums1[i]];
    }
    for (int i = 0; i < nums2.size(); ++i) {
        if (--mp[nums2[i]] >= 0) intersections.push_back(nums2[i]);
    }
    return intersections;
}

// time: O(m + n)
// space: O(m) or O(n)

//vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
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
//        }
//    }
//    return intersections;
//}
//
//// time: O(mlogm + nlogn)
//// space: O(1)