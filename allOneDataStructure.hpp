//
// Created by 李研 on 2020/2/11.
//

#ifndef MYLEETCODE_ALLONEDATASTRUCTURE_HPP
#define MYLEETCODE_ALLONEDATASTRUCTURE_HPP

/*
 * 432. All O`one Data Structure
 * https://leetcode.com/problems/all-oone-data-structure/
 */

#include "DataStructureDefinition.h"

class AllOne {
private:
    struct CountNode {
        int count;
        unordered_set<string> keys;
    };

    unordered_map<string, list<CountNode>::iterator> _m;
    list<CountNode> _l;

public:
    /** Initialize your data structure here. */
    AllOne() {}

    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        auto mit = _m.find(key);
        if (mit == _m.end()) {
            if (!_l.empty() && _l.front().count == 1) {
                _l.front().keys.insert(key);
            } else {
                _l.push_front({1, {key}});
            }
            _m[key] = _l.begin();
        } else {
            auto curr_lit = mit->second;
            auto next_lit = next(curr_lit);
            if (next_lit != _l.end() && next_lit->count == curr_lit->count + 1) {
                next_lit->keys.insert(key);
            } else {
                next_lit = _l.insert(next_lit, {curr_lit->count + 1, {key}});
            }
            remove(curr_lit, key);
            _m[key] = next_lit;
        }
    }

    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        auto mit = _m.find(key);
        if (mit == _m.end()) return;
        auto curr_lit = mit->second;
        if (curr_lit->count == 1) {
            _m.erase(key);
        } else {
            auto prev_lit = prev(curr_lit);
            if (curr_lit != _l.begin() && prev_lit->count == curr_lit->count - 1) {
                prev_lit->keys.insert(key);
            } else {
                prev_lit = _l.insert(curr_lit, {curr_lit->count - 1, {key}});
            }
            _m[key] = prev_lit;
        }
        remove(curr_lit, key);
    }

    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        return _l.empty() ? "" : *_l.back().keys.begin();
    }

    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        return _l.empty() ? "" : *_l.front().keys.begin();
    }

private:
    void remove(list<CountNode>::iterator lit, string key) {
        lit->keys.erase(key);
        if (lit->keys.empty())
            _l.erase(lit);
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */

#endif //MYLEETCODE_ALLONEDATASTRUCTURE_HPP
