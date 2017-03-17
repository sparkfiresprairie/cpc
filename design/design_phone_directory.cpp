//
// Created by Xingyuan Wang on 3/17/17.
//

/*
    Design a Phone Directory which supports the following operations:

    get: Provide a number which is not assigned to anyone.
    check: Check if a number is available or not.
    release: Recycle or release a number.
    Example:

    // Init a phone directory containing a total of 3 numbers: 0, 1, and 2.
    PhoneDirectory directory = new PhoneDirectory(3);

    // It can return any available phone number. Here we assume it returns 0.
    directory.get();

    // Assume it returns 1.
    directory.get();

    // The number 2 is available, so return true.
    directory.check(2);

    // It returns 2, the only number that is left.
    directory.get();

    // The number 2 is no longer available, so return false.
    directory.check(2);

    // Release number 2 back to the pool.
    directory.release(2);

    // Number 2 is available again, return true.
    directory.check(2);
 */

#include "Design.h"

class PhoneDirectory {
    vector<int> free_list;
    vector<bool> free_ht;
    int index, count;
public:
    /** Initialize your data structure here
        @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    PhoneDirectory(int maxNumbers) : index(0), count(maxNumbers), free_list(maxNumbers), free_ht(maxNumbers, true) {
        for (int i = 0; i < maxNumbers; ++i) {
            free_list[i] = i;
        }
    }

    /** Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available. */
    int get() {
        int n = -1;
        if (index < count) {
            n = free_list[index++];
            free_ht[n] = false;
        }
        return n;
    }

    /** Check if a number is available or not. */
    bool check(int number) {
        if (number < 0 || number >= count) {
            return false;
        }
        return free_ht[number];
    }

    /** Recycle or release a number. */
    void release(int number) {
        if (number < 0 || number >= count || free_ht[number]) return;
        free_list[--index] = number;
        free_ht[number] = true;
    }
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj.get();
 * bool param_2 = obj.check(number);
 * obj.release(number);
 */