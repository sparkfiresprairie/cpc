//
// Created by Xingyuan Wang on 3/26/17.
//

/*
    Given a collection of intervals, merge all overlapping intervals.

    For example,
    Given [1,3],[2,6],[8,10],[15,18],
    return [1,6],[8,10],[15,18].
 */

#include "Sort.h"

vector <Interval> merge(vector <Interval> &intervals) {
    vector <Interval> ans;
    if (intervals.empty()) return ans;
    auto less_than = [](Interval const &a, Interval const &b) { return a.start < b.start; };
    sort(intervals.begin(), intervals.end(), less_than);
    ans.push_back(intervals[0]);
    int i = 0;
    for (int j = 1; j < intervals.size(); ++j) {
        if (ans[i].end < intervals[j].start) {
            ans.push_back(intervals[j]);
            ++i;
        } else if (ans[i].end >= intervals[j].start && ans[i].end <= intervals[j].end) {
            ans[i].end = intervals[j].end;
        }
    }
    return ans;
}

// time: O(nlogn)
// space: O(1)