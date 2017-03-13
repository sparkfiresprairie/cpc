//
// Created by Xingyuan Wang on 3/13/17.
//

/*
    Total Accepted: 86288
    Total Submissions: 322549
    Difficulty: Hard
    Contributors: Admin
    Given a set of non-overlapping intervals, insert a new interval into the intervals
    (merge if necessary).

    You may assume that the intervals were initially sorted according to their start times.

    Example 1:
    Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

    Example 2:
    Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].

    This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
 */

#include "Sort.h"

vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
    vector<Interval> ans;
    int i = 0;
    int n = intervals.size();
    while (i < n && intervals[i].end < newInterval.start) {
        ans.push_back(intervals[i]);
        ++i;
    }
    while (i < n && intervals[i].end >= newInterval.start && intervals[i].start <= newInterval.end) {
        newInterval.start = min(newInterval.start, intervals[i].start);
        newInterval.end = max(newInterval.end, intervals[i].end);
        ++i;
    }
    ans.push_back(newInterval);
    while (i < n && intervals[i].start > newInterval.end) {
        ans.push_back(intervals[i]);
        ++i;
    }
    return ans;
}

// time: O(nlogn)
// space: O(1)