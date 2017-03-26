//
// Created by Xingyuan Wang on 3/26/17.
//

#include "String.h"

string addBinary(string a, string b) {
    string s;
    int i = a.size() - 1;
    int j = b.size() - 1;
    int c = 0;
    while (i >= 0 || j >= 0 || c == 1) {
        c += (i >= 0) ? a[i--] - '0' : 0;
        c += (j >= 0) ? b[j--] - '0' : 0;
        s = char(c % 2 + '0') + s;
        c /= 2;
    }
    return s;
}

// time: O(m + n)
// space: O(1)
