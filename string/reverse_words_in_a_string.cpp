//
// Created by Xingyuan Wang on 3/13/17.
//

/*
    Given an input string, reverse the string word by word.

    For example,
    Given s = "the sky is blue",
    return "blue is sky the".

    Update (2015-02-12):
    For C programmers: Try to solve it in-place in O(1) space.

    click to show clarification.

    Clarification:
    What constitutes a word?
    A sequence of non-space characters constitutes a word.
    Could the input string contain leading or trailing spaces?
    Yes. However, your reversed string should not contain leading
    or trailing spaces.
    How about multiple spaces between two words?
    Reduce them to a single space in the reversed string.
 */

#include "String.h"

void reverseWords(string &s) {
    reverse(s.begin(), s.end());
    int idx = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == ' ') continue;
        if (idx != 0) s[idx++] = ' ';
        int b = idx;
        while (i < s.size() && s[i] != ' ') {
            s[idx++] = s[i++];
        }
        reverse(s.begin() + b, s.begin() + idx);
    }
    s.erase(s.begin() + idx, s.end());
}

// time: O(n)
// space: O(1)

//void reverseWords(string &s) {
//    istringstream iss(s);
//    string token;
//    vector<string> words;
//    while (iss >> token) {
//        words.push_back(token);
//    }
//    reverse(words.begin(), words.end());
//    string sep = "";
//    s = "";
//    for (auto const& word : words) {
//        s.append(sep + word);
//        sep = " ";
//    }
//}

// time: O(# of words)
// space: O(# of words)