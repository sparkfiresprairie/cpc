//
// Created by Xingyuan Wang on 3/12/17.
//

/*
    Given an array of integers that is already sorted in ascending order, find two
    numbers such that they add up to a specific target number.

    The function twoSum should return indices of the two numbers such that they add
    up to the target, where index1 must be less than index2. Please note that your
    returned answers (both index1 and index2) are not zero-based.

    You may assume that each input would have exactly one solution and you may not
    use the same element twice.

    Input: numbers={2, 7, 11, 15}, target=9
    Output: index1=1, index2=2
 */

#include "Array.h"

vector<int> twoSum(vector<int>& numbers, int target) {
    vector<int> indices(2, 0);
    int low = 0, high = numbers.size() - 1;
    while (low < high) {
        if (numbers[low] + numbers[high] == target) {
            indices[0] = low + 1;
            indices[1] = high + 1;
            break;
        } else if (numbers[low] + numbers[high] > target) {
            --high;
        } else {
            ++low;
        }
    }
    return indices;
}

// time: O(n)
// space: O(1)
