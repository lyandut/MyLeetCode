//
// Created by 李研 on 2019/5/18.
//

// 380. 常数时间插入、删除和获取随机元素

#ifndef MYLEETCODE_INSERTDELETEGETRANDOMO1_H
#define MYLEETCODE_INSERTDELETEGETRANDOMO1_H

#include <iostream>
#include <unordered_map>

using namespace std;

class RandomizedSet {
public:
    /** Initialize your data structure here. */
    unordered_map<int, bool> myMap;
    RandomizedSet() {
    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(myMap[val]) { return false; }
        myMap[val] = true;
        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(!myMap.count(val)) { return false; }
        myMap.erase(val);
        return true;
    }

    /** Get a random element from the set. */
    int getRandom() {
        auto iter = myMap.begin();
        int index = rand() % myMap.size();
        while(index){
            iter++;
            index--;
        }
        return (*iter).first;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */


#endif //MYLEETCODE_INSERTDELETEGETRANDOMO1_H
