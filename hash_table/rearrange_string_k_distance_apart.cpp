//
// Created by Xingyuan Wang on 3/17/17.
//

/*
    Given a non-empty string s and an integer k, rearrange the string such that
    the same characters are at least distance k from each other.

    All input strings are given in lowercase letters. If it is not possible to
    rearrange the string, return an empty string "".

    Example 1:
    s = "aabbcc", k = 3

    Result: "abcabc"

    The same letters are at least distance 3 from each other.
    Example 2:
    s = "aaabc", k = 3

    Answer: ""

    It is not possible to rearrange the string.
    Example 3:
    s = "aaadbbcc", k = 2

    Answer: "abacabcd"

    Another possible answer is: "abcabcda"

    The same letters are at least distance 2 from each other.
 */

#include "HashTable.h"

int find_candidate(vector<int> const& count, vector<int> const& valid, int idx) {
    int max_count = std::numeric_limits<int>::min();
    int candidate_idx = -1;
    for (int i = 0; i < count.size(); ++i) {
        if (count[i] > 0 && count[i] > max_count && idx >= valid[i]) {
            max_count = count[i];
            candidate_idx = i;
        }
    }
    return candidate_idx;
}

string rearrangeString(string str, int k) {
    int n = str.size();
    vector<int> count(26, 0);
    vector<int> valid(26, 0);
    for (int i = 0; i < n; ++i) {
        ++count[str[i] - 'a'];
    }
    string ans;
    for (int i = 0; i < n; ++i) {
        int candidate_idx = find_candidate(count, valid, i);
        if (candidate_idx == -1) return "";
        --count[candidate_idx];
        valid[candidate_idx] = i + k;
        ans += 'a' + candidate_idx;
    }
    return ans;
}

// time: O(n)
// space: O(1)

/*
    Task 1, 2, 3. Each task takes 1s to finish and need 2s for cooldown.
    Now the order of the tasks is 1,1,2,3,2.
    1. How many seconds it takes to finish all the tasks without changing the order?
    8s. 1__123_2
    2. What if you can change the order?
 */


string taskOrderInOrder(string const& tasks, int t) {  // t is the cool down time
    int n = tasks.size();
    vector<int> valid(26, 0);
    string ans;
    for (int i = 0; i < n; ++i) {
        int candidate_idx = tasks[i] - 'a';
        while (valid[candidate_idx] > ans.size()) {
            ans += "_";
        }
        valid[candidate_idx] = ans.size() + t + 1;
        ans += 'a' + candidate_idx;
    }
    return ans;
}

// time: O(n)
// space: O(1)

int findCandidate(vector<int> const& count, vector<int> const& valid, int idx) {
    int max_count = 0;
    int candidate_idx = -1;
    for (int i = 0; i < count.size(); ++i) {
        if (count[i] > 0 && count[i] > max_count && idx >= valid[i]) {
            max_count = count[i];
            candidate_idx = i;
        }
    }
    return candidate_idx;
}


string taskOrderOutOfOrder(string const& tasks, int t) {
    int n = tasks.size();
    vector<int> count(26, 0);
    vector<int> valid(26, 0);
    for (int i = 0; i < n; ++i) {
        ++count[tasks[i] - 'a'];
    }
    string ans;
    for (int i = 0; i < n; ++i) {
        int candidate_idx = -1;
        while (true) {
            candidate_idx = findCandidate(count, valid, ans.size());
            if (candidate_idx != -1) break;
            ans += "_";
        }
        --count[candidate_idx];
        valid[candidate_idx] = i + t + 1;
        ans += 'a' + candidate_idx;
    }
    return ans;
}

// time: O(n)
// space: O(1)