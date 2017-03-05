//
// Created by Xingyuan Wang on 3/1/17.
//

/*
    Implement a basic calculator to evaluate a simple expression string.

    The expression string may contain open ( and closing parentheses ), the plus + or minus sign -,
    non-negative integers and empty spaces .

    You may assume that the given expression is always valid.

    Some examples:
    "1 + 1" = 2
    " 2-1 + 2 " = 3
    "(1+(4+5+2)-3)+(6+8)" = 23
    Note: Do not use the eval built-in library function.
 */

#include "Stack.h"

int calculate(string s) {
    stack<int> nums, signs;
    int num = 0, ans = 0, sign = 1;
    for (char c : s) {
        // digit: it should be one digit from the current number
        if (isdigit(c)) num = num * 10 + c - '0';
            // number is over
        else {
            ans += sign * num;
            num = 0;
            // '+': number is over, we can add the previous number and start a new number
            if (c == '+') sign = 1;
                // '-': same as above
            else if (c == '-') sign = -1;
                // '(': push the previous result and the sign into the stack, set result to 0,
                // just calculate the new result within the parenthesis.
            else if (c == '(') {
                nums.push(ans);
                signs.push(sign);
                ans = 0;
                sign = 1;
            } else if (c == ')') {  // ')': pop out the top two numbers from stack, first one is
                // the sign before this pair of parenthesis, second is the
                // temporary result before this pair of parenthesis. We add them
                // together.
                ans = signs.top() * ans + nums.top();
                signs.pop();
                nums.pop();
            }
        }
    }
    ans += sign * num;
    return ans;
}