//
// Created by Xingyuan Wang on 3/6/17.
//

/*
    Given an array nums, there is a sliding window of size k which is moving from the very left of
    the array to the very right. You can only see the k numbers in the window. Each time the sliding
    window moves right by one position.

    For example,
    Given nums = [1,3,-1,-3,5,3,6,7], and k = 3.

    Window position                Max
    ---------------               -----
    [1  3  -1] -3  5  3  6  7       3
     1 [3  -1  -3] 5  3  6  7       3
     1  3 [-1  -3  5] 3  6  7       5
     1  3  -1 [-3  5  3] 6  7       5
     1  3  -1  -3 [5  3  6] 7       6
     1  3  -1  -3  5 [3  6  7]      7
    Therefore, return the max sliding window as [3,3,5,5,6,7].

    Note:
    You may assume k is always valid, ie: 1 ≤ k ≤ input array's size for non-empty array.

    Follow up:
    Could you solve it in linear time?

    Hint:

    How about using a data structure such as deque (double-ended queue)?
    The queue size need not be the same as the window’s size.
    Remove redundant elements and the queue should store only elements that need to be considered.
 */

#include "Array.h"

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> buffer;
    vector<int> ans;
    for (int i = 0; i < nums.size(); ++i) {
        while (!buffer.empty() && nums[i] >= nums[buffer.back()]) buffer.pop_back();
        buffer.push_back(i);
        if (i >= k - 1) ans.push_back(nums[buffer.front()]);
        if (buffer.front() <= i - (k - 1)) buffer.pop_front();
    }
    return ans;
}

// time: O(n)
// space: O(n)

// The following algorithm doesn't work. st.erase can't erase element.
// don't know why.
//vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//    vector<int> ans;
//    auto my_greater = [&](int idx1, int idx2) {
//        return nums[idx1] >= nums[idx2];
//    };
//    set<int, decltype(my_greater)> st(my_greater);
//    for (int i = 0; i < nums.size(); ++i) {
//        st.insert(i);
//        if (i < k - 1) continue;
//        ans.push_back(nums[*st.begin()]);
//        st.erase(i - (k - 1));
//    }
//    return ans;
//}