//
// Created by Xingyuan Wang on 3/17/17.
//

/*
    Check whether the original sequence org can be uniquely reconstructed from the sequences
    in seqs. The org sequence is a permutation of the integers from 1 to n, with 1 ≤ n ≤ 104.
    Reconstruction means building a shortest common supersequence of the sequences in seqs
    (i.e., a shortest sequence so that all sequences in seqs are subsequences of it).
    Determine whether there is only one sequence that can be reconstructed from seqs and
    it is the org sequence.

    Example 1:

    Input:
    org: [1,2,3], seqs: [[1,2],[1,3]]

    Output:
    false

    Explanation:
    [1,2,3] is not the only one sequence that can be reconstructed, because [1,3,2] is also
    a valid sequence that can be reconstructed.
    Example 2:

    Input:
    org: [1,2,3], seqs: [[1,2]]

    Output:
    false

    Explanation:
    The reconstructed sequence can only be [1,2].
    Example 3:

    Input:
    org: [1,2,3], seqs: [[1,2],[1,3],[2,3]]

    Output:
    true

    Explanation:
    The sequences [1,2], [1,3], and [2,3] can uniquely reconstruct the original sequence [1,2,3].
    Example 4:

    Input:
    org: [4,1,5,2,6,3], seqs: [[5,2,6,3],[4,1,5,2]]

    Output:
    true
    UPDATE (2017/1/8):
    The seqs parameter had been changed to a list of list of strings (instead of a 2d array of
    strings). Please reload the code definition to get the latest changes.
 */

#include "TopologicalSort.h"

bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
    unordered_map<int, vector<int>> g;
    vector<int> indegree(org.size() + 1, -1);    // 1 to n, 0 is dummy
    for (auto const& seq : seqs) {
        for (int i = 0; i < seq.size(); ++i) {
            if (seq[i] < 1 || seq[i] > org.size()) return false;
            if (g.find(seq[i]) == g.end()) {
                g.insert({seq[i], {}});
                indegree[seq[i]] = 0;
            }
            if (i > 0) {
                g[seq[i - 1]].push_back(seq[i]);
                ++indegree[seq[i]];
            }
        }
    }
    queue<int> q;
    for (int i = 1; i < indegree.size(); ++i) {
        if (indegree[i] < 0) return false;  // number of vertices doesn't match
        if (indegree[i] == 0) q.push(i);
    }

    int idx = 0;
    while (!q.empty()) {
        if (q.size() > 1) return false; // not the only choice
        int cur = q.front();
        q.pop();
        if (org[idx++] != cur) return false;
        for (auto nb : g[cur]) {
            --indegree[nb];
            if (indegree[nb] == 0) q.push(nb);
        }
    }
    return idx == org.size();
}

