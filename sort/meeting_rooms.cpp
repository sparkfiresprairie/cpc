//
// Created by Xingyuan Wang on 3/6/17.
//

/*
    Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei),
    determine if a person could attend all meetings.

    For example,
    Given [[0, 30],[5, 10],[15, 20]],
    return false.
 */

#include "Sort.h"

bool canAttendMeetings(vector<Interval>& intervals) {
    auto less_than = [](Interval const& a, Interval const& b) { return a.start < b.start; };
    sort(intervals.begin(), intervals.end(), less_than);
    if (intervals.empty()) return true;
    Interval cur = intervals[0];
    for (int i = 1; i < intervals.size(); ++i) {
        if (cur.end > intervals[i].start) return false;
        cur = intervals[i];
    }
    return true;
}
