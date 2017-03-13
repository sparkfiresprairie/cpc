//
// Created by Xingyuan Wang on 3/13/17.
//

/*
    Shuffle a set of numbers without duplicates.

    Example:

    // Init an array with set 1, 2, and 3.
    int[] nums = {1,2,3};
    RandomShuffleArray solution = new RandomShuffleArray(nums);

    // Shuffle the array [1,2,3] and return its result. Any permutation of [1,2,3] must equally likely to be returned.
    solution.shuffle();

    // Resets the array back to its original configuration [1,2,3].
    solution.reset();

    // Returns the random shuffling of array [1,2,3].
    solution.shuffle();
 */

#include "Design.h"

class RandomShuffleArray {
private:
    vector<int> nums;
public:
    RandomShuffleArray(vector<int> nums) : nums(nums){}

    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return nums;
    }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> result(nums);
        for (int i = 0; i < result.size(); ++i) {
            int pos = rand() % (result.size() - i);
            swap(result[i + pos], result[i]);
        }
        return result;
    }
};

