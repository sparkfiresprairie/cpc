//
// Created by Xingyuan Wang on 3/12/17.
//

/*
    Design and implement a TwoSum class. It should support the following operations:
    add and find.

    add - Add the number to an internal data structure.
    find - Find if there exists any pair of numbers which sum is equal to the value.

    For example,
    add(1); add(3); add(5);
    find(4) -> true
    find(7) -> false
 */

#include "Design.h"

class TwoSum {
private:
    unordered_map<int, int> mp;
public:

    // Add the number to an internal data structure.
    void add(int number) {
        ++mp[number];
    }

    // Find if there exists any pair of numbers which sum is equal to the value.
    bool find(int value) {
        for (auto const& e : mp) {
            int i = e.first;
            int target = value - i;
            if (target == i && mp[i] > 1 || target != i && mp.find(target) != mp.end()) return true;
        }
        return false;
    }
};


// Your TwoSum object will be instantiated and called as such:
// TwoSum twoSum;
// twoSum.add(number);
// twoSum.find(value);

// time: add - O(1), find - O(n)
// space: O(n)

//class TwoSum {
//private:
//    unordered_set<int> sums;
//    unordered_set<int> nums;
//public:
//    void add(int number) {
//        if (nums.find(number) != nums.end()) {
//            sums.insert(2 * number);
//        } else {
//            for (auto num : nums) {
//                sums.insert(num + number);
//            }
//            nums.insert(number);
//        }
//    }
//
//    bool find(int value) {
//        return sums.find(value) !=  sums.end();
//    }
//};

//time: find - O(1), add - O(n)
//space: O(n^2)