//
// Created by Xingyuan Wang on 3/5/17.
//

#ifndef CPC_LINKEDLIST_H
#define CPC_LINKEDLIST_H

#include <iostream>
#include <vector>
#include <queue>
#include <cstdlib>
#include <cmath>
#include <string>
#include <map>
#include <set>
#include <unordered_set>
#include <list>
#include <unordered_map>
#include <stack>
#include <deque>
#include <fstream>
#include <chrono>


using std::max;
using std::min;
using std::string;
using std::to_string;
using std::swap;
using std::vector;
using std::priority_queue;
using std::queue;
using std::map;
using std::pair;
using std::set;
using std::unordered_set;
using std::list;
using std::unordered_map;
using std::deque;
using std::multiset;
using std::stack;
using std::ifstream;

// Definitions
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

struct RandomListNode {
    int label;
    RandomListNode *next, *random;

    RandomListNode(int x) : label(x), next(nullptr), random(nullptr) { }
};

struct TreeLinkNode {
    int val;
    TreeLinkNode* left;
    TreeLinkNode* right;
    TreeLinkNode* next;
    TreeLinkNode(int x) : val(x), left(nullptr), right(nullptr), next(nullptr) {}
};

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode*> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

class Iterator {
    using IT = vector<int>::const_iterator;
    IT b;
    IT e;
public:
    bool hasNext() {
        return b != e;
    }
    int next() {
        return *b++;
    }
    int peek() const {
        return *b;
    };
    Iterator(IT b, IT e) : b(b), e(e) {}
};

#endif //CPC_LINKEDLIST_H
