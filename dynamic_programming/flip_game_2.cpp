//
// Created by Xingyuan Wang on 3/10/17.
//

/*
    You are playing the following Flip Game with your friend: Given a string that contains
    only these two characters: + and -, you and your friend take turns to flip two consecutive
    "++" into "--". The game ends when a person can no longer make a move and therefore the
    other person will be the winner.

    Write a function to determine if the starting player can guarantee a win.

    For example, given s = "++++", return true. The starting player can guarantee a win by
    flipping the middle "++" to become "+--+".

    Follow up:
    Derive your algorithm's runtime complexity.
 */

#include "DynamicProgramming.h"

bool help(string s, unordered_set<string>& can_win_set) {
    if (can_win_set.find(s) != can_win_set.end()) return true;
    for (int i = 0; i + 1 < s.size(); ++i) {
        if (s[i] == '+' && s[i + 1] == '+') {
            string t = s;
            s[i] = '-';
            s[i + 1] = '-';
            if (!help(s, can_win_set)) {
                can_win_set.insert(t);
                return true;  // here we must pass by value
            }
            s[i + 1] = '+';
            s[i] = '+';
        }
    }
    return false;
}

bool canWin(string s) {
    unordered_set<string> can_win_set;
    return help(s, can_win_set);
}

// time: T(N) = (N-2) * T(N-2) = (N-2) * (N-4) * T(N-4) ... = (N-2) * (N-4) * (N-6) * ... ~ O(N!!)
// space: O(N)
