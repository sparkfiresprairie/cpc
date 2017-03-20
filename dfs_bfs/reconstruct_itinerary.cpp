//
// Created by Xingyuan Wang on 3/19/17.
//

#include <mach/vm_region.h>

/*
    Given a list of airline tickets represented by pairs of departure and arrival airports
    [from, to], reconstruct the itinerary in order. All of the tickets belong to a man who
    departs from JFK. Thus, the itinerary must begin with JFK.

    Note:
    If there are multiple valid itineraries, you should return the itinerary that has the
    smallest lexical order when read as a single string. For example, the itinerary
    ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
    All airports are represented by three capital letters (IATA code).
    You may assume all tickets form at least one valid itinerary.
    Example 1:
    tickets = [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
    Return ["JFK", "MUC", "LHR", "SFO", "SJC"].
    Example 2:
    tickets = [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
    Return ["JFK","ATL","JFK","SFO","ATL","SFO"].
    Another possible reconstruction is ["JFK","SFO","ATL","JFK","ATL","SFO"]. But it is
    larger in lexical order.
 */

#include "DFSBFS.h"

using graph = unordered_map<string, priority_queue<string, vector<string>, std::greater<string>>>;

void dfs(string const& departure, graph& g, vector<string>& ans) {
    while (!g[departure].empty()) {
        string next = g[departure].top();
        g[departure].pop();
        dfs(next, g, ans);
    }
    ans.push_back(departure);
}

vector<string> findItinerary(vector<pair<string, string>> tickets) {
    graph g;
    vector<string> ans;
    for (auto const& ticket : tickets) {
        g[ticket.first].push(ticket.second);
    }
    dfs("JFK", g, ans);
    reverse(ans.begin(), ans.end());
    return ans;
}

