//
// Created by Xingyuan Wang on 3/28/17.
//

/*
    Given two non-negative integers num1 and num2 represented as strings,
    return the product of num1 and num2.

    Note:

    The length of both num1 and num2 is < 110.
    Both num1 and num2 contains only digits 0-9.
    Both num1 and num2 does not contain any leading zero.
    You must not use any built-in BigInteger library or convert the inputs
    to integer directly.
 */

#include "Math.h"

string multiply(string num1, string num2) {
    string ans(num1.size() + num2.size(), '0');
    for (int i = num1.size() - 1; i >= 0; --i) {
        int carry = 0;
        for (int j = num2.size() - 1; j >=0; --j) {
            int tmp = (ans[i + j + 1] - '0') + (num1[i] - '0') * (num2[j] - '0') + carry;
            ans[i + j + 1] = tmp % 10 + '0';
            carry = tmp / 10;
        }
        ans[i] += carry;    // should have been sum[i + j + 1], j == -1, so just i;
    }

    int i;
    for (i = 0; i < ans.size(); ++i) {
        if (ans[i] != '0') break;
    }
    if (i == ans.size()) return "0";
    else return ans.substr(i);
}