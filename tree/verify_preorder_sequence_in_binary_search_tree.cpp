//
// Created by Xingyuan Wang on 3/7/17.
//

/*
    Given an array of numbers, verify whether it is the correct preorder traversal sequence of a binary search tree.

    You may assume each number in the sequence is unique.

    Follow up:
    Could you do it using only constant space complexity?
 */

#include "Tree.h"

bool verifyPreorder(vector<int>& preorder) {
    int low = INT_MIN;
    stack<int> stk;
    for (auto p : preorder) {
        if (p < low) return false;
        while(!stk.empty() && p > stk.top()) {
            low = stk.top();
            stk.pop();
        }
        stk.push(p);
    }
    return true;
}

// time: O(n)
// space: O(log n)

//bool verifyPreorder(vector<int>& preorder) {
//    int low = INT_MIN;  // it is actually the parent of right sub tree
//    stack<int> stk;
//    for (auto p : preorder) {
//        if (p < low) return false;
//        while(!stk.empty() && p > stk.top()) {
//            low = stk.top();
//            stk.pop();
//        }
//        stk.push(p);
//    }
//    return true;
//}
//
//// time: O(n)
//// space: O(1)