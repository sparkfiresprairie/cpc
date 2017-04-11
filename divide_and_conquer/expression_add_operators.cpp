//
// Created by Xingyuan Wang on 3/9/17.
//

/*
    Given a string that contains only digits 0-9 and a target value, return all possibilities
    to add binary operators (not unary) +, -, or * between the digits so they evaluate to the
    target value.

    Examples:
    "123", 6 -> ["1+2+3", "1*2*3"]
    "232", 8 -> ["2*3+2", "2+3*2"]
    "105", 5 -> ["1*0+5","10-5"]
    "00", 0 -> ["0+0", "0-0", "0*0"]
    "3456237490", 9191 -> []
 */

#include "DivideAndConquer.h"

// Given target (i.e. target) and number (i.e. num & pos), find a place to insert a operator
// so that eval + leftvalue (i.e. value) + rightvalue == target
// When reaching the end of the num, no right chars any more
// so eval + value == target;
void help(vector<string>& ans, string path, string const& num, int target, int pos, long eval, long multed) {
    if (pos == num.size()) {
        if (eval == target) ans.push_back(path);
        return;
    }
    for (int i = pos; i < num.size(); ++i) {
        if (i != pos && num[pos] == '0') break;     // we can not have number started with 0
        // except 0 itself
        string str = num.substr(pos, i - pos + 1);
        long value = stol(str);
        if (pos == 0) {     // because the first operand doesn't have a operator before it;
            help(ans, path + str, num, target, i + 1, value, value);
        } else {
            // for example, if you have a sequence of 12345 and you have proceeded to 1 + 2 + 3,
            // now your eval is 6 right? If you want to add a * between 3 and 4, you would take
            // 3 as the digit to be multiplied, so you want to take it out from the existing eval.
            // You have 1 + 2 + 3 * 4 and the eval now is (1 + 2 + 3) - 3 + (3 * 4).
            help(ans, path + "+" + str, num, target, i + 1, eval + value, value);
            help(ans, path + "-" + str, num, target, i + 1, eval - value, -value);
            help(ans, path + "*" + str, num, target, i + 1, eval - multed + multed * value, multed * value);
        }
    }
}


vector<string> addOperators(string num, int target) {
    vector<string> ans;
    if (num.empty()) return ans;
    help(ans, "", num, target, 0, 0, 0);
    return ans;
}

// time: O(4^n)
// space: O(n) if considering stack depth
