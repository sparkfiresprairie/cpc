//
// Created by Xingyuan Wang on 3/6/17.
//

/*
    A strobogrammatic number is a number that looks the same when rotated 180 degrees
    (looked at upside down).

    Write a function to count the total strobogrammatic numbers that exist in the range
    of low <= num <= high.

    For example,
    Given low = "50", high = "100", return 3. Because 69, 88, and 96 are three
    strobogrammatic numbers.

    Note:
    Because the range might be a large number, the low and high numbers are represented
    as string.
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

int strobogrammaticInRange3(string low, string high) {
    int count = 0;
    vector<string> result;
    for (int i = low.size(); i <= high.size(); ++i) {
        vector<string> t;
        help(t, i, i);
        result.insert(result.end(), t.begin(), t.end());
    }
    for (auto const& num : result) {
        if(( num.size() == low.size() && num.compare(low) < 0 ) || (num.size() == high.size() && num.compare(high) > 0)) continue;
        ++count;
    }
    return count;
}

