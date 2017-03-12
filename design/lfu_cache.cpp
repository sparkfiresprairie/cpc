//
// Created by Xingyuan Wang on 3/12/17.
//

/*
    Design and implement a data structure for Least Frequently Used (LFU) cache. It should support the following operations: get and put.

    get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
    put(key, value) - Set or insert the value if the key is not already present. When the cache reaches its capacity, it should invalidate the least frequently used item before inserting a new item. For the purpose of this problem, when there is a tie (i.e., two or more keys that have the same frequency), the least recently used key would be evicted.

    Follow up:
    Could you do both operations in O(1) time complexity?

    Example:

    LFUCache cache = new LFUCache( 2 );

    cache.put(1, 1);
    cache.put(2, 2);
    cache.get(1);       // returns 1
    cache.put(3, 3);    // evicts key 2
    cache.get(2);       // returns -1 (not found)
    cache.get(3);       // returns 3.
    cache.put(4, 4);    // evicts key 1.
    cache.get(1);       // returns -1 (not found)
    cache.get(3);       // returns 3
    cache.get(4);       // returns 4
 */

#include "Design.h"

class LFUCache {
private:
    struct ListNode {
        int value;
        int key;
    };

    struct MapNode {
        int freq;
        list<ListNode>::iterator iter;
    };
private:
    int cap;
    int sz;
    int min_freq;
    unordered_map<int, MapNode> mp1;
    unordered_map<int, list<ListNode>> mp2;
public:
    LFUCache(int capacity) : cap(capacity), sz(0) {}

    int get(int key) {
        if (mp1.find(key) == mp1.end()) return -1;
        int f_pre = mp1[key].freq++;
        int f_cur = mp1[key].freq;
        mp2[f_cur].push_front(*mp1[key].iter);
        mp2[f_pre].erase(mp1[key].iter);
        mp1[key].iter = mp2[f_cur].begin();

        if (mp2[min_freq].empty()) ++min_freq;

        return mp1[key].iter->value;
    }

    void put(int key, int value) {
        if (cap <= 0) return;
        if (mp1.find(key) != mp1.end()) {
            get(key);
            mp1[key].iter->value = value;
        } else {
            if (sz == cap) {
                mp1.erase(mp2[min_freq].back().key);
                mp2[min_freq].pop_back();
                --sz;
            }
            mp2[1].push_front({value, key});
            mp1.insert({key, {1, mp2[1].begin()}});
            min_freq = 1;
            ++sz;
        }

    }
};

// time: get, put - O(1)
// space: O(n)