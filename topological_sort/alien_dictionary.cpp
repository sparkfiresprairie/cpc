//
// Created by Xingyuan Wang on 3/8/17.
//

/*
    There is a new alien language which uses the latin alphabet. However, the order among letters are
    unknown to you. You receive a list of non-empty words from the dictionary, where words are sorted
    lexicographically by the rules of this new language. Derive the order of letters in this language.

    Example 1:
    Given the following words in dictionary,

    [
      "wrt",
      "wrf",
      "er",
      "ett",
      "rftt"
    ]
    The correct order is: "wertf".

    Example 2:
    Given the following words in dictionary,

    [
      "z",
      "x"
    ]
    The correct order is: "zx".

    Example 3:
    Given the following words in dictionary,

    [
      "z",
      "x",
      "z"
    ]
    The order is invalid, so return "".

    Note:
    You may assume all letters are in lowercase.
    You may assume that if a is a prefix of b, then a must appear before b in the given dictionary.
    If the order is invalid, return an empty string.
    There may be multiple valid order of letters, return any one of them is fine.
 */

#include "TopologicalSort.h"

using graph = unordered_map<char, unordered_set<char>>;

bool hasCycle(graph& g, char c, unordered_set<char>& visited, unordered_set<char>& onpath, string& order) {
    if (onpath.find(c) != onpath.end()) return true;
    if (visited.find(c) == visited.end()) {
        onpath.insert(c);
        for (auto next : g[c]) {
            if (hasCycle(g, next, visited, onpath, order)) return true;
        }
        visited.insert(c);
        onpath.erase(c);
        order += c;
    }
    return false;
}

string topological_sort(graph& g) {
    string order;
    unordered_set<char> visited;
    unordered_set<char> onpath;
    for (auto const& kv : g) {
        if (visited.find(kv.first) == visited.end() && hasCycle(g, kv.first, visited, onpath, order)) return "";
    }
    reverse(order.begin(), order.end());
    return order;
}

graph build_graph(vector<string>& words) {
    graph g;
    for (int i = 0; i + 1 < words.size(); ++i) {
        string const& w1 = words[i];
        string const& w2 = words[i + 1];
        int sz1 = w1.size(), sz2 = w2.size();
        bool found = false;
        for (int j = 0; j < max(sz1, sz2); ++j) {
            if (j < sz1 && g.find(w1[j]) == g.end()) g.insert({w1[j], {}});
            if (j < sz2 && g.find(w2[j]) == g.end()) g.insert({w2[j], {}});
            if (j < sz1 && j < sz2 && w1[j] != w2[j] && !found) {
                g[w1[j]].insert(w2[j]);
                found = true;
            }
            // corner case: ["wrtkj","wrt"], it should return ""
            if(!found && j <= sz1 && j <= sz2 && !w1.substr(j).empty() && w2.substr(j).empty()) {
                return {};
            }
        }
    }
    return g;
}

string alienOrder(vector<string>& words) {
    if (words.empty()) return "";
    if (words.size() == 1) return words[0];
    graph g = build_graph(words);
    return topological_sort(g);
}






