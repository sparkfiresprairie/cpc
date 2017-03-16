//
// Created by Xingyuan Wang on 3/14/17.
//

/*
    Remove the minimum number of invalid parentheses in order to make the input
    string valid. Return all possible results.

    Note: The input string may contain letters other than the parentheses ( and ).

    Examples:
    "()())()" -> ["()()()", "(())()"]
    "(a)())()" -> ["(a)()()", "(a())()"]
    ")(" -> [""]
 */

#include "DFSBFS.h"

bool isValid(string const& s) {
    int count = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '(') ++count;
        else if (s[i] == ')') {
            if (count > 0) --count;
            else return false;
        }
    }
    return count == 0;
}

vector<string> removeInvalidParentheses(string s) {
    vector<string> ans;
    unordered_set<string> visited;
    queue<string> candidates;
    candidates.push(s);
    bool found = false;
    while (!candidates.empty()) {
        int size = candidates.size();
        for (int i = 0; i < size; ++i) {
            string t = candidates.front();
            candidates.pop();

            if (isValid(t)) {
                ans.push_back(t);
                found = true;   // stop at the current level
            }

            if (found) continue;

            for (int i = 0; i < t.size(); ++i) {
                string child = t.substr(0, i) + t.substr(i + 1, t.size() - i - 1);
                if (visited.find(child) == visited.end()) {
                    visited.insert(child);
                    candidates.push(child);
                }
            }
        }
        if (found) break;
    }
    return ans;
}

// time: O(n*2^n)
// space: O(2^n)

//// last_i: where my parent node find the first mismatch right parentheses. For the child node
//// it just need to start from last_i since chars before last_i has been garanteed valid
//// last_j: where my parent node remove the mismatch right parentheses. For the child node
//// it just need to start from last_j to avoid duplicate
//void remove(string s, vector<string>& ans, int last_i, int last_j, vector<char> const& p) {
//    int count = 0, i = last_i;
//    // check whether current s is a valid answer: right parentheses <= left parentheses
//    while (i < s.size()) {
//        if (s[i] == p[0]) ++count;
//        if (s[i] == p[1]) --count;
//        if (count < 0) break;
//        ++i;
//    }
//
//    if (i < s.size()) {         // this means s is not a valid answer
//        for (int j = last_j; j <= i; ++j) {
//            // we restrict ourself to remove the first ) in a series of concecutive )s.
//            // However, we need to keep another information: the last removal position.
//            // If we do not have this position, we will generate duplicate by removing
//            // two ‘)’ in two steps only with a different order.
//            if (s[j] == p[1] && (j == last_j || s[j - 1] != p[1])) {
//                remove(s.substr(0, j) + s.substr(j + 1, s.size() - j - 1), ans, i, j, p);
//            }
//        }
//    } else {                    // this means s is a valid answer (leaf node)
//        reverse(s.begin(), s.end());
//        if (p[0] == '(') {      // check whether it is the first round or the second round
//            // it is 1st round, we need to check 2nd round
//            // to make sure left parentheses <= right parentheses
//            remove(s, ans, 0, 0, {')', '('});
//        } else {
//            // it is 2nd round, s is one of the final answers we need
//            // push is into ans vector
//            ans.push_back(s);
//        }
//    }
//}
//
//vector<string> removeInvalidParentheses(string s) {
//    vector<string> ans;
//    remove(s, ans, 0, 0, {'(', ')'});
//    return ans;
//}

// time: O()




