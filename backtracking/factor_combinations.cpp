//
// Created by Xingyuan Wang on 3/7/17.
//

/*
    Numbers can be regarded as product of its factors. For example,

    8 = 2 x 2 x 2;
      = 2 x 4.
    Write a function that takes an integer n and return all possible combinations of its factors.

    Note:
    You may assume that n is always positive.
    Factors should be greater than 1 and less than n.
    Examples:
    input: 1
    output:
    []
    input: 37
    output:
    []
    input: 12
    output:
    [
      [2, 6],
      [2, 2, 3],
      [3, 4]
    ]
    input: 32
    output:
    [
      [2, 16],
      [2, 2, 8],
      [2, 2, 2, 4],
      [2, 2, 2, 2, 2],
      [2, 4, 4],
      [4, 8]
    ]
 */

#include "BackTracking.h"

void help(int n, int f, vector<int>& combination, vector<vector<int>>& combinations) {
    if (n <= 1) {
        if (combination.size() > 1) {
            combinations.push_back(combination);
        }
        return;
    }
    for (int i = f; i <= n; ++i) {
        if (n % i == 0) {
            combination.push_back(i);
            help(n / i, i, combination, combinations);
            combination.pop_back();
        }
    }
}

vector<vector<int>> getFactors(int n) {
    vector<vector<int>> combinations;
    vector<int> combination;
    help(n, 2, combination, combinations);
    return combinations;
}

