//
// Created by 李研 on 2020/2/13.
//

#ifndef MYLEETCODE_FINDMEDIANFROMDATASTREAM_HPP
#define MYLEETCODE_FINDMEDIANFROMDATASTREAM_HPP

#include "DataStructureAndAlgorithm.h"

/*
 * 295. Find Median from Data Stream
 * https://leetcode.com/problems/find-median-from-data-stream/
 * [两个优先队列找中位数]
 */

namespace leetcode295 {

class MedianFinder {
private:
    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, greater<>> min_heap;

public:
    /** initialize your data structure here. */
    MedianFinder() {}

    void addNum(int num) {
        if (max_heap.empty() || num <= max_heap.top()) {
            max_heap.push(num);
            if (max_heap.size() - min_heap.size() > 1) {
                min_heap.push(max_heap.top());
                max_heap.pop();
            }
        } else {
            min_heap.push(num);
            if (min_heap.size() > max_heap.size()) {
                max_heap.push(min_heap.top());
                min_heap.pop();
            }
        }
    }

    double findMedian() {
        return max_heap.size() == min_heap.size() ? 0.5 * (max_heap.top() + min_heap.top()) : max_heap.top();
    }
};

}

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

#endif //MYLEETCODE_FINDMEDIANFROMDATASTREAM_HPP
