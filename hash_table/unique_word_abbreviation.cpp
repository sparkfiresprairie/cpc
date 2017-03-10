//
// Created by Xingyuan Wang on 3/9/17.
//

/*
    An abbreviation of a word follows the form <first letter><number><last letter>.
    Below are some examples of word abbreviations:

    a) it                      --> it    (no abbreviation)

         1
    b) d|o|g                   --> d1g

                  1    1  1
         1---5----0----5--8
    c) i|nternationalizatio|n  --> i18n

                  1
         1---5----0
    d) l|ocalizatio|n          --> l10n
    Assume you have a dictionary and given a word, find whether its abbreviation is
    unique in the dictionary. A word's abbreviation is unique if no other word from
    the dictionary has the same abbreviation.

    Example:
    Given dictionary = [ "deer", "door", "cake", "card" ]

    isUnique("dear") ->
    false

    isUnique("cart") ->
    true

    isUnique("cane") ->
    false

    isUnique("make") ->
    true

 */

#include "HashTable.h"

class ValidWordAbbr {
private:
    unordered_map<string, unordered_set<string>> mp;
    string getAbbr(string const& s) {
        int n = s.size();
        return n > 2 ? s[0] + to_string(n - 2) + s.back() : s;
    }
public:
    ValidWordAbbr(vector<string> dictionary) {
        for (auto const& s : dictionary) {
            mp[getAbbr(s)].insert(s);
        }
    }

    bool isUnique(string word) {
        string abbr = getAbbr(word);
        return mp.find(abbr) == mp.end() || mp[abbr].size() == 1 && mp[abbr].find(word) != mp[abbr].end();
    }
};

/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr obj = new ValidWordAbbr(dictionary);
 * bool param_1 = obj.isUnique(word);
 */