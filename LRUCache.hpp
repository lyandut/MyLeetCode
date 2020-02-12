//
// Created by liyan on 2019-06-06.
//

/*
 * 146. LRU Cache
 * https://leetcode.com/problems/lru-cache/
 */

#ifndef MYLEETCODE_LRUCACHE_HPP
#define MYLEETCODE_LRUCACHE_HPP

#include "DataStructureDefinition.h"

class LRUCache {
private:
    using PairList = list<pair<int, int>>;

    int cacheCapacity;
    PairList cacheList;
    unordered_map<int, PairList::iterator> cacheMap;

public:
    LRUCache(int capacity) : cacheCapacity(capacity) {}

    int get(int key) {
        auto iter = cacheMap.find(key);
        if (iter == cacheMap.end()) { return -1; }
        cacheList.splice(cacheList.begin(), cacheList, iter->second);
        return iter->second->second;
        // OR
        // return cacheList.begin()->second;
    }

    void put(int key, int value) {
        auto iter = cacheMap.find(key);
        if (iter != cacheMap.end()) {
            cacheList.splice(cacheList.begin(), cacheList, iter->second);
            // iter->second->second = value;
            // OR
            cacheList.begin()->second = value;
        } else {
            cacheList.push_front(make_pair(key, value));
            cacheMap[key] = cacheList.begin();

            if (cacheList.size() > cacheCapacity) {
                cacheMap.erase(cacheList.back().first);
                cacheList.pop_back();
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

#endif //MYLEETCODE_LRUCACHE_HPP
