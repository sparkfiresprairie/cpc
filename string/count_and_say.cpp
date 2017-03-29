//
// Created by Xingyuan Wang on 3/28/17.
//

/*
    The count-and-say sequence is the sequence of integers beginning as follows:
    1, 11, 21, 1211, 111221, ...

    1 is read off as "one 1" or 11.
    11 is read off as "two 1s" or 21.
    21 is read off as "one 2, then one 1" or 1211.
    Given an integer n, generate the nth sequence.

    Note: The sequence of integers will be represented as a string.
 */

#include "String.h"

string countAndSay(int n) {
    string ans;
    if (!n) return ans;
    ans = "1";
    for (int i = 1; i < n; ++i) {
        int count = 0;
        string t;
        for (int i = 0; i < ans.size(); ++i) {
            ++count;
            if (i + 1 == ans.size() || i + 1 < ans.size() && ans[i] != ans[i + 1]) {
                t.append(to_string(count) + ans[i]);
                count = 0;
            }
        }
        ans = t;
    }
    return ans;
}

