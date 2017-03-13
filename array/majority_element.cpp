//
// Created by Xingyuan Wang on 3/13/17.
//

#include "Array.h"

int majorityElement(vector<int>& nums) {
    int candidate = 0;
    int count = 0;
    for (int i = 0; i < nums.size(); ++i) {
        if ( count == 0 ) {
            candidate = nums[i];
            count = 1;
            continue;
        }
        if ( candidate == nums[i] ) count++;
        else count--;
    }
    return candidate;
}

// time: O(n)
// space: O(1)