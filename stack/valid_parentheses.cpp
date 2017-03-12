//
// Created by Xingyuan Wang on 3/12/17.
//

/*
    Given a string containing just the characters '(', ')', '{', '}', '[' and ']',
    determine if the input string is valid.

    The brackets must close in the correct order, "()" and "()[]{}" are all valid
    but "(]" and "([)]" are not.
 */

#include "Stack.h"

bool isValid(string s) {
    unordered_map<char, char> mp{{')', '('}, {']', '['}, {'}', '{'}};
    stack<char> stk;
    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') stk.push(c);
        else {
            if (stk.empty() || stk.top() != mp[c]) return false;
            stk.pop();
        }
    }
    return stk.empty();
}