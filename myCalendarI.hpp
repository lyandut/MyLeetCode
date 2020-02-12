//
// Created by 李研 on 2020/2/9.
//

#ifndef MYLEETCODE_MYCALENDARI_HPP
#define MYLEETCODE_MYCALENDARI_HPP

/*
 * 729. My Calendar I
 * https://leetcode.com/problems/my-calendar-i/
 * 优化：二分查找插入、BST
 */

#include "DataStructureAndAlgorithm.h"

class MyCalendar {
private:
    vector<tuple<int, int, int>> startEndInterval;

public:
    MyCalendar() {}

    bool book(int start, int end) {
        if (startEndInterval.empty()) {
            startEndInterval.emplace_back(start, end, end - start);
            return true;
        }
        if (start >= get<1>(*startEndInterval.rbegin())) {
            startEndInterval.emplace_back(start, end, end - start);
            return true;
        }
        if (end <= get<0>(*startEndInterval.begin())) {
            startEndInterval.insert(startEndInterval.begin(), make_tuple(start, end, end - start));
            return true;
        } else {
            for (int i = 0; i < startEndInterval.size(); i++) {
                if (start >= get<1>(startEndInterval[i]) && end <= get<0>(startEndInterval[i + 1])) {
                    startEndInterval.insert(startEndInterval.begin() + i + 1, make_tuple(start, end, end - start));
                    return true;
                }
                if (start >= get<0>(startEndInterval[i]) && start < get<1>(startEndInterval[i]))
                    return false;
                if (end > get<0>(startEndInterval[i]) && end < get<1>(startEndInterval[i]))
                    return false;
            }
        }
        return false;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */

#endif //MYLEETCODE_MYCALENDARI_HPP
