//
// Created by Xingyuan Wang on 3/6/17.
//

/*
    A strobogrammatic number is a number that looks the same when rotated 180 degrees
    (looked at upside down).

    Find all strobogrammatic numbers that are of length = n.

    For example,
    Given n = 2, return ["11","69","88","96"].

    Hint:

    Try to use recursion and notice that it should recurse with n - 2 instead of n - 1.
 */

#include "Recursion.h"

void help(vector<string>& ans, int n, int m) {
    if (n == 0) {
        ans.push_back("");
        return;
    }
    if (n == 1) {
        ans.push_back("0");
        ans.push_back("1");
        ans.push_back("8");
        return;
    }
    help(ans, n - 2, m);
    int sz = ans.size();
    for (int i = 0; i < sz; ++i) {
        if (n != m) ans.push_back("0" + ans[i] + "0");
        ans.push_back("1" + ans[i] + "1");
        ans.push_back("8" + ans[i] + "8");
        ans.push_back("6" + ans[i] + "9");
        ans.push_back("9" + ans[i] + "6");
    }
    ans.erase(ans.begin(), ans.begin() + sz);
}

vector<string> findStrobogrammatic2(int n) {
    vector<string> ans;
    help(ans, n, n);
    return ans;
}

// time: 5^(n/2)
// space: O(n/2) stack space + O(5^(n/2)) the number of solutions in the vector

