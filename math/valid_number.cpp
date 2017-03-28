//
// Created by Xingyuan Wang on 3/27/17.
//

/*
    Validate if a given string is numeric.

    Some examples:
    "0" => true
    " 0.1 " => true
    "abc" => false
    "1 a" => false
    "2e10" => true
    Note: It is intended for the problem statement to be ambiguous. You should
    gather all requirements up front before implementing one.
 */

#include "Math.h"

bool isNumber(string s) {
    int i = 0;
    while (i < s.size() && s[i] == ' ') ++i;
    s.erase(0, i);
    i = s.size() - 1;
    while (i >= 0 && s[i] == ' ') --i;
    s.erase(i + 1, s.size() - i - 1);


    bool point_seen = false;
    bool e_seen = false;
    bool number_seen = false;
    bool number_after_e = true;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] >= '0' && s[i] <= '9') {
            number_seen = true;
            number_after_e = true;
        } else if (s[i] == '.') {
            if (e_seen || point_seen) return false;
            point_seen = true;
        } else if (s[i] == 'e') {
            if (e_seen || !number_seen) return false;
            e_seen = true;
            number_after_e = false;
        } else if (s[i] == '-' || s[i] == '+') {
            if (i != 0 && s[i - 1] != 'e') return false;
        } else {
            return false;
        }
    }
    return number_seen && number_after_e;
}

// time: O(n)
// space: O(1)
