//
// Created by Xingyuan Wang on 3/6/17.
//

/*
    Given a string of numbers and operators, return all possible results from computing all the
    different possible ways to group numbers and operators. The valid operators are +, - and *.


    Example 1
    Input: "2-1-1".

    ((2-1)-1) = 0
    (2-(1-1)) = 2
    Output: [0, 2]


    Example 2
    Input: "2*3-4*5"

    (2*(3-(4*5))) = -34
    ((2*3)-(4*5)) = -14
    ((2*(3-4))*5) = -10
    (2*((3-4)*5)) = -10
    (((2*3)-4)*5) = 10
    Output: [-34, -14, -10, -10, 10]
 */

#include "DivideAndConquer.h"

vector<int> help(string const& input, int b, int e, unordered_map<string, vector<int>>& memo) {
    vector<int> ans;
    string key = to_string(b) + "-" + to_string(e);
    if (memo.find(key) != memo.end()) return memo[key];
    for (int i = b; i <= e; ++i) {
        char c = input[i];
        if (c == '+' || c == '-' || c == '*') {
            vector<int> left = help(input, b, i - 1, memo);
            vector<int> right = help(input, i + 1, e, memo);
            for (auto n1 : left) {
                for (auto n2 : right) {
                    if (c == '+') {
                        ans.push_back(n1 + n2);
                    } else if (c == '-') {
                        ans.push_back(n1 - n2);
                    } else if (c == '*') {
                        ans.push_back(n1 * n2);
                    }
                }
            }
        }
    }
    if (ans.empty()) {
        ans.push_back(stoi(input.substr(b, e - b + 1)));
    }
    memo.insert({key, ans});
    return ans;
}

vector<int> diffWaysToCompute(string input) {
    unordered_map<string, vector<int>> memo;
    return help(input, 0, input.size() - 1, memo);
}



