//
// Created by Xingyuan Wang on 3/5/17.
//

/*
    Implement a basic calculator to evaluate a simple expression string.

    The expression string contains only non-negative integers, +, -, *, / operators and empty spaces . The integer division should truncate toward zero.

    You may assume that the given expression is always valid.

    Some examples:
    "3+2*2" = 7
    " 3/2 " = 1
    " 3+5 / 2 " = 5
    Note: Do not use the eval built-in library function.
 */

#include "Stack.h"

int calculate2(string s) {
    int n = s.size();
    if (n == 0) return 0;
    vector<int> stk;
    int num = 0;
    char sign = '+';
    for (int i = 0; i < n; ++i) {
        if (isdigit(s[i])) {
            num = num * 10 + s[i] - '0';
        }
        // when i == len - 1, we have to do the computation, so we use if instead of else if
        if (!isdigit(s[i]) && s[i] != ' ' || i == n - 1) {
            if (sign == '+') {
                stk.push_back(num);
            } else if (sign == '-') {
                stk.push_back(-num);
            } else if (sign == '*') {
                int t = stk.back() * num;
                stk.pop_back();
                stk.push_back(t);
            } else if (sign == '/') {
                int t = stk.back() / num;
                stk.pop_back();
                stk.push_back(t);
            }
            sign = s[i];
            num = 0;
        }
    }
    int ans = 0;
    for (int i : stk) {
        ans += i;
    }
    return ans;
}