//
// Created by Xingyuan Wang on 3/20/17.
//

/*
    Write a function that takes a string as input and reverse only the vowels of a string.

    Example 1:
    Given s = "hello", return "holle".

    Example 2:
    Given s = "leetcode", return "leotcede".

    Note:
    The vowels does not include the letter "y".
 */

#include "String.h"

bool is_vowel(char c) {
    c = tolower(c);
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}


string reverseVowels(string s) {
    int i = 0, j = s.size() - 1;
    while (i <= j) {
        while (i <= j && !is_vowel(s[i])) ++i;
        while (i <= j && !is_vowel(s[j])) --j;
        if (i > j) break;
        swap(s[i++], s[j--]);
    }
    return s;
}

