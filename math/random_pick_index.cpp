//
// Created by Xingyuan Wang on 4/14/17.
//

/*
    Given an array of integers with possible duplicates, randomly output the index of a given
    target number. You can assume that the given target number must exist in the array.

    Note:
    The array size can be very large. Solution that uses too much extra space will not pass
    the judge.

    Example:

    int[] nums = new int[] {1,2,3,3,3};
    Solution solution = new Solution(nums);

    // pick(3) should return either index 2, 3, or 4 randomly. Each index should have equal
    probability of returning.
    solution.pick(3);

    // pick(1) should return 0. Since in the array only nums[0] is equal to 1.
    solution.pick(1);
 */

#include "Math.h"

class Solution {
    vector<int> v;
public:
    Solution(vector<int> nums) {
        v = nums;
    }
    // For the nth target, ++count is n. Then the probability that rand() % count == 0 is 1/n.
    // Thus, the probability that return nth target is 1/n.
    // For (n-1)th target, the probability of returning it is (n-1)/n * 1/(n-1) = 1/n.
    int pick(int target) {
        int result = -1;
        int count = 0;
        for (int i = 0; i < v.size(); ++i) {
            if (v[i] == target) {
                ++count;
                if (rand() % count == 0) result = i;
            }
        }
        return result;
    }
};


// time: O(n)
// space: O(1)