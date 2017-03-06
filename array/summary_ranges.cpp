//
// Created by Xingyuan Wang on 3/5/17.
//

/*
    Given a sorted integer array without duplicates, return the summary of its ranges.

    For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].
 */

#include "Array.h"

string getRange(int a, int b) {
    if (a == b) return to_string(a);
    else {
        return to_string(a) + "->" + to_string(b);
    }
}

vector<string> summaryRanges(vector<int>& nums) {
    vector<string> ans;
    for (int i = 0; i < nums.size(); ++i) {
        int j = i;
        while (i + 1 < nums.size() && nums[i + 1] == nums[i] + 1) {
            ++i;
        }
        ans.push_back(getRange(nums[j], nums[i]));
    }
    return ans;
}

// time: O(n)
// space: O(n)

