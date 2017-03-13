//
// Created by Xingyuan Wang on 3/12/17.
//

/*
    Given n non-negative integers representing an elevation map where the width
    of each bar is 1, compute how much water it is able to trap after raining.

    For example,
    Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
 */

#include "Array.h"

int trap(vector<int>& height) {
    if (height.size() < 3) return 0;
    int tallest = 0;
    for (int i = 0; i < height.size(); ++i) {
        if (height[tallest] < height[i]) tallest = i;
    }
    int water = 0;
    for (int i = 0, tall = 0; i < tallest; ++i) {
        if (tall < height[i]) tall = height[i];
        else water += tall - height[i];
    }
    for (int i = height.size() - 1, tall = 0; i > tallest; --i) {
        if (tall < height[i]) tall = height[i];
        else water += tall - height[i];
    }
    return water;
}

// time: O(n)
// space: O(1)

//int trap(vector<int>& height) {
//    int n = height.size();
//    int left = 0, right = n - 1;
//    int max_left = 0, max_right = 0;
//    int ans = 0;
//    while (left <= right) {
//        if (height[left] <= height[right]) {
//            if (height[left] >= max_left) max_left = height[left];
//            else ans += max_left - height[left];
//            ++left;
//        } else {
//            if (height[right] >= max_right) max_right = height[right];
//            else ans += max_right - height[right];
//            --right;
//        }
//    }
//    return ans;
//}