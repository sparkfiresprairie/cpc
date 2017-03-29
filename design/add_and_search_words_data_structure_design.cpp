//
// Created by Xingyuan Wang on 3/28/17.
//

/*
    Design a data structure that supports the following two operations:

    void addWord(word)
    bool search(word)
    search(word) can search a literal word or a regular expression string containing
    only letters a-z or .. A . means it can represent any one letter.

    For example:

    addWord("bad")
    addWord("dad")
    addWord("mad")
    search("pad") -> false
    search("bad") -> true
    search(".ad") -> true
    search("b..") -> true
    Note:
    You may assume that all words are consist of lowercase letters a-z.
 */

#include "Design.h"

class TrieNode {
public:
    bool is_end;
    vector<TrieNode*> children;
    TrieNode() : is_end(false), children(26, nullptr) {}
    ~TrieNode() {
        for (int i = 0; i < 26; ++i) {
            delete children[i];
        }
    }
};

class WordDictionary {
    TrieNode* root;
public:
    WordDictionary() {
        root = new TrieNode();
    }

    ~WordDictionary() {
        delete root;
    }
    // Adds a word into the data structure.
    void addWord(string word) {
        TrieNode* p = root;
        for (int i = 0; i < word.size(); ++i) {
            int index = word[i] - 'a';
            if (!p->children[index]) p->children[index] = new TrieNode();
            p = p->children[index];
        }
        p->is_end = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.

    bool match(char c, int i) {
        return c == '.' || c - 'a' == i;
    }
    bool search(string word) {
        return help(word, 0, root);
    }

    bool help(string const& word, int b, TrieNode* root) {
        if (b == word.size()) return root->is_end;
        for (int i = 0; i < 26; ++i) {
            if (!match(word[b], i)) continue;
            if (!root->children[i]) continue;
            if (help(word, b + 1, root->children[i])) return true;
        }
        return false;
    }
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");