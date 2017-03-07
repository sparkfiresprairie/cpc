//
// Created by Xingyuan Wang on 3/6/17.
//

/*
    Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei),
    find the minimum number of conference rooms required.

    For example,
    Given [[0, 30],[5, 10],[15, 20]],
    return 2.
 */

#include "Sort.h"

int minMeetingRooms(vector<Interval>& intervals) {
    vector<pair<int, int>> changes;
    for (auto const& interval : intervals) {
        changes.push_back({interval.start, 1});
        changes.push_back({interval.end, -1});
    }
    sort(changes.begin(), changes.end());
    int ans = 0, rooms = 0;
    for (auto const& change : changes) {
        ans = max(ans, rooms += change.second);
    }
    return ans;
}
