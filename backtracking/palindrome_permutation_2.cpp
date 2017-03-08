//
// Created by Xingyuan Wang on 3/8/17.
//

/*
    Given a string s, return all the palindromic permutations (without duplicates) of it.
    Return an empty list if no palindromic permutation could be form.

    For example:

    Given s = "aabb", return ["abba", "baab"].

    Given s = "abc", return [].

    Hint:

    If a palindromic permutation exists, we just need to generate the first half of the
    string.
    To generate all distinct permutations of a (half of) string, use a similar approach
    from: Permutations II or Next Permutation.
 */

#include "BackTracking.h"

void help(int length, string s, string mid, vector<string>& ans, vector<int>& mp) {
    if (s.size() == length) {
        string t = s;
        reverse(s.begin(), s.end());
        ans.push_back(t + mid + s);
        return;
    }
    for (int i = 0; i < 256; ++i) {
        if (mp[i] > 0) {
            --mp[i];
            help(length, s + char(i), mid, ans, mp);
            ++mp[i];
        }
    }
}

vector<string> generatePalindromes(string s) {
    vector<string> ans;
    vector<int> mp(256, 0);
    int num_odds = 0;
    for (auto c : s) {
        ++mp[c];
        num_odds = (mp[c] % 2 == 0) ? num_odds - 1 : num_odds + 1;
    }
    if (num_odds > 1) return ans;
    string mid;
    int length = 0;
    for (int i = 0; i < 256; ++i) {
        if (mp[i] > 0) {
            if (mp[i] % 2 == 1) {
                mid += char(i);
                --mp[i];
            }
            mp[i] /= 2;
            length += mp[i];
        }
    }
    help(length, "", mid, ans, mp);
    return ans;
}




