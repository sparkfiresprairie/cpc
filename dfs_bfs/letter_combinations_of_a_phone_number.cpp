//
// Created by Xingyuan Wang on 3/12/17.
//

/*
    Given a digit string, return all possible letter combinations that the
    number could represent.

    A mapping of digit to letters (just like on the telephone buttons) is
    given below.



    Input:Digit string "23"
    Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
    Note:
    Although the above answer is in lexicographical order, your answer
    could be in any order you want.
 */

#include "DFSBFS.h"

vector<string> letterCombinations(string digits) {
    vector<string> ans;
    if (digits.empty()) return ans;
    unordered_map<int, string> mp{{0, ""}, {1, ""}, {2, "abc"}, {3, "def"}, {4, "ghi"}, {5, "jkl"}, {6, "mno"}, {7, "pqrs"}, {8, "tuv"}, {9, "wxyz"}};
    queue<string> q;
    q.push("");
    for (int i = 0; i < digits.size(); ++i) {
        int n = q.size();
        for (int j = 0; j < n; ++j) {
            string s = q.front();
            q.pop();
            string t = mp[digits[i] - '0'];
            for (int k = 0; k < t.size(); ++k) {
                q.push(s + t[k]);
            }
        }
    }
    while (!q.empty()) {
        ans.push_back(q.front());
        q.pop();
    }
    return ans;
}

// time: O(4^n)
// space: O(4^n)

//vector<string> letterCombinations(string digits) {
//    vector<string> ans;
//    if (digits.empty()) return ans;
//    string path;
//    help(digits, 0, path, ans);
//    return ans;
//}
//
//void help(string const& digits, int b, string& path, vector<string>& ans) {
//    unordered_map<int, string> map{{1, ""}, {2, "abc"}, {3, "def"}, {4, "ghi"}, {5, "jkl"}, {6, "mno"}, {7, "pqrs"}, {8, "tuv"}, {9, "wxyz"}, {0, ""}};
//    if (b >= digits.size()) {
//        ans.push_back(path);
//        return;
//    }
//
//    for (auto& c : map[digits[b] - '0']) {
//        path.push_back(c);
//        help(digits, b + 1, path, ans);
//        path.pop_back();
//    }
//}
