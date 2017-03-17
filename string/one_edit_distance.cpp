//
// Created by Xingyuan Wang on 3/17/17.
//

/*
    Given two strings S and T, determine if they are both one edit distance apart.
 */

#include "String.h"

bool isOneEditDistance(string s, string t) {
    if (s == t) return false;
    int sz_s = s.size();
    int sz_t = t.size();
    if (sz_s > sz_t) return isOneEditDistance(t, s);
    bool same_length = sz_s == sz_t;
    if (sz_t - sz_s <= 1) {
        bool found = false;
        for (int i = 0, j = 0; i < sz_s; ++i, ++j) {
            if (s[i] != t[j]) {
                if (found) return false;
                else {
                    found = true;
                    if (!same_length) --i;
                }
            }
        }
    } else return false;
    return true;
}

