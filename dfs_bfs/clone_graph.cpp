//
// Created by Xingyuan Wang on 3/27/17.
//

/*
    Clone an undirected graph. Each node in the graph contains a label and a
    list of its neighbors.


    OJ's undirected graph serialization:
    Nodes are labeled uniquely.

    We use # as a separator for each node, and , as a separator for node label
    and each neighbor of the node.
    As an example, consider the serialized graph {0,1,2#1,2#2,2}.

    The graph has a total of three nodes, and therefore contains three parts as
    separated by #.

    First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
    Second node is labeled as 1. Connect node 1 to node 2.
    Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming
    a self-cycle.
    Visually, the graph looks like the following:

           1
          / \
         /   \
        0 --- 2
             / \
             \_/
 */

#include "DFSBFS.h"

UndirectedGraphNode* help(UndirectedGraphNode* node, unordered_map<UndirectedGraphNode*, UndirectedGraphNode*>& mp) {
    if (!node) return nullptr;
    if (mp.find(node) == mp.end()) {
        mp[node] = new UndirectedGraphNode(node->label);
        for (auto nb : node->neighbors) {
            mp[node]->neighbors.push_back(help(nb, mp));
        }
    }
    return mp[node];
}

UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
    unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> mp;
    return help(node, mp);
}

// time: O(V + E)

