//
// Created by Xingyuan Wang on 3/13/17.
//

/*
    Find the kth largest element in an unsorted array. Note that it is the kth
    largest element in the sorted order, not the kth distinct element.

    For example,
    Given [3,2,1,5,6,4] and k = 2, return 5.

    Note:
    You may assume k is always valid, 1 ≤ k ≤ array's length.
 */

#include "Array.h"

int partition(vector<int>& nums, int left, int right) {
    int pivot = nums[right];
    int idx = left;
    for (int i = left; i < right; ++i) {
        if (nums[i] > pivot) {
            swap(nums[i], nums[idx++]);
        }
    }
    swap(nums[idx], nums[right]);
    return idx;
}

int findKthLargest(vector<int>& nums, int k) {
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
        int pos = partition(nums, left, right);
        if (pos == k - 1) return nums[pos];
        if (pos > k - 1) right = pos - 1;
        else left = pos + 1;
    }
    return 0;
}

// time: amortised O(n), worst case O(n^2)
// space: O(1)


//int findKthLargest(vector<int>& nums, int k) {
//    priority_queue<int, vector<int>, std::greater<int>> pq;
//    for (auto num : nums) {
//        if (pq.size() < k) {
//            pq.push(num);
//        } else {
//            if (num <= pq.top()) continue;
//            pq.pop();
//            pq.push(num);
//        }
//    }
//    return pq.top();
//}

// time: O(nlogk)
// space: O(k)

