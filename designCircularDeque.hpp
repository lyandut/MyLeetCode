/*
 * 641. Design Circular Deque
 * https://leetcode.com/problems/design-circular-deque/
 *【循环队列】
 */

#ifndef MYLEETCODE_DESIGNCIRCULARDEQUE_HPP
#define MYLEETCODE_DESIGNCIRCULARDEQUE_HPP

#include "DataStructureAndAlgorithm.h"

class MyCircularDeque {
private:
    vector<int> _vec;
    int _head;
    int _tail;
    int _size;

public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        _size = k + 1; // tail不存数据，循环队列会浪费一个数组的存储空间
        _vec.resize(_size, 0);
        _head = _tail = 0;
    }

    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if (isFull()) { return false; }
        _head = (_head - 1 + _size) % _size;
        _vec[_head] = value;
        return true;
    }

    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if (isFull()) { return false; }
        _vec[_tail] = value;
        _tail = (_tail + 1) % _size;
        return true;
    }

    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if (isEmpty()) { return false; }
        _head = (_head + 1) % _size;
        return true;
    }

    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if (isEmpty()) { return false; }
        _tail = (_tail - 1 + _size) % _size;
        return true;
    }

    /** Get the front item from the deque. */
    int getFront() {
        if (isEmpty()) { return -1; }
        return _vec[_head];
    }

    /** Get the last item from the deque. */
    int getRear() {
        if (isEmpty()) { return -1; }
        return _vec[(_tail - 1 + _size) % _size];
    }

    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return _head == _tail;
    }

    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return (_tail + 1) % _size == _head;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */

#endif // MYLEETCODE_DESIGNCIRCULARDEQUE_HPP