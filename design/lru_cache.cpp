//
// Created by Xingyuan Wang on 3/12/17.
//

/*
    Design and implement a data structure for Least Recently Used (LRU) cache. It should support
    the following operations: get and put.

    get(key) - Get the value (will always be positive) of the key if the key exists in the cache,
    otherwise return -1.
    put(key, value) - Set or insert the value if the key is not already present. When the cache
    reached its capacity, it should invalidate the least recently used item before inserting a
    new item.

    Follow up:
    Could you do both operations in O(1) time complexity?

    Example:

    LRUCache cache = new LRUCache( 2 );

    cache.put(1, 1);
    cache.put(2, 2);
    cache.get(1);       // returns 1
    cache.put(3, 3);    // evicts key 2
    cache.get(2);       // returns -1 (not found)
    cache.put(4, 4);    // evicts key 1
    cache.get(1);       // returns -1 (not found)
    cache.get(3);       // returns 3
    cache.get(4);       // returns 4
 */

#include "Design.h"

class LRUCache {
public:
    LRUCache(int capacity) : capacity(capacity) {}

    int get(int key) {
        if (mp.find(key) == mp.end()) return -1;
        l.push_front(*mp[key]);
        l.erase(mp[key]);
        mp[key] = l.begin();
        return mp[key]->first;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            l.push_front(*mp[key]);
            l.erase(mp[key]);
            mp[key] = l.begin();
            mp[key]->first = value;
        } else {
            if (mp.size() == capacity) {
                int victim = l.back().second;
                l.pop_back();
                mp.erase(victim);
            }
            l.push_front({value, key});
            mp[key] = l.begin();
        }
    }
private:
    int capacity;
    list<pair<int, int>> l;
    unordered_map<int, list<pair<int, int>>::iterator> mp;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */

// time: get, put - O(1)
// space: O(capacity)

//class LRUCache {
//public:
//    LRUCache(int capacity) : capacity(capacity) {}
//
//    int get(int key) {
//        if (mp.find(key) == mp.end()) return -1;
//        touch(key);
//        return mp[key]->first;
//    }
//
//    void put(int key, int value) {
//        if (mp.find(key) == mp.end()) {
//            if (mp.size() == capacity) {
//                int victim = l.back().second;
//                l.pop_back();
//                mp.erase(victim);
//            }
//            l.push_front({value, key});
//            mp.insert({key, l.begin()});
//        }
//        touch(key);
//        mp[key]->first = value;
//    }
//private:
//    int capacity;
//    list<pair<int, int>> l;
//    unordered_map<int, list<pair<int, int>>::iterator> mp;
//    void touch(int key) {
//        l.push_front(*mp[key]);
//        l.erase(mp[key]);
//        mp[key] = l.begin();
//    }
//};