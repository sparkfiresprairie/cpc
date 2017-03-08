//
// Created by Xingyuan Wang on 3/8/17.
//

/*
    Given a string, determine if a permutation of the string could form a palindrome.

    For example,
    "code" -> False, "aab" -> True, "carerac" -> True.

    Hint:

    Consider the palindromes of odd vs even length. What difference do you notice?
    Count the frequency of each character.
    If each character occurs even number of times, then it must be a palindrome. How
    about character which occurs odd number of times?
 */

#include "HashTable.h"

bool canPermutePalindrome(string s) {
    vector<int> mp(256, 0);
    int num_odds = 0;
    for (auto c : s) {
        ++mp[c];
        num_odds = (mp[c] % 2 == 0) ? num_odds - 1 : num_odds + 1;
    }
    return num_odds <= 1;
}

// time: O(n)
// space: O(1)
