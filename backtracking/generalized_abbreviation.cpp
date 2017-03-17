//
// Created by Xingyuan Wang on 3/17/17.
//

/*
    Write a function to generate the generalized abbreviations of a word.

    Example:
    Given word = "word", return the following list (order does not matter):
    ["word", "1ord", "w1rd", "wo1d", "wor1", "2rd", "w2d", "wo2", "1o1d",
    "1or1", "w1r1", "1o2", "2r1", "3d", "w3", "4"]
 */

#include "BackTracking.h"


/* The idea is: for every character, we can keep it or abbreviate it. To keep it,
 * we add it to the current solution and carry on backtracking. To abbreviate it,
 * we omit it in the current solution, but increment the count, which indicates
 * how many characters have we abbreviated. When we reach the end or need to put
 * a character in the current solution, and count is bigger than zero, we add the
 * number into the solution. */
void help(vector<string>& ans, string const& word, int b, string cur, int count) {
    if (b == word.size()) {
        if (count > 0) cur += to_string(count);
        ans.push_back(cur);
        return;
    }
    help(ans, word, b + 1, cur, count + 1);     // omit current char;
    help(ans, word, b + 1, cur + (count > 0 ? to_string(count) : "") + word[b], 0);    // keep current char
}

vector<string> generateAbbreviations(string word) {
    vector<string> ans;
    help(ans, word, 0, "", 0);
    return ans;
}
