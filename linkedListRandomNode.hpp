//
// Created by 李研 on 2020/2/13.
//

#ifndef MYLEETCODE_LINKEDLISTRANDOMNODE_HPP
#define MYLEETCODE_LINKEDLISTRANDOMNODE_HPP

/*
 * 382. Linked List Random Node
 * https://leetcode.com/problems/linked-list-random-node/
 * [水塘抽样]
 */

#include "DataStructureAndAlgorithm.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
namespace leetcode382 {

class Solution {
private:
    ListNode *_head;

public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode *head) {
        _head = head;
    }

    /** Returns a random node's value. */
    int getRandom() {
        if (_head == nullptr) return 0;
        int res = _head->val;
        int cnt = 1;
        ListNode *curr = _head->next;
        while (curr) {
            ++cnt;
            if (rand() % cnt == 0) { // 以 1/cnt 的概率用 curr->val 替换 res
                res = curr->val;
            }
            curr = curr->next;
        }
        return res;
    }
};

}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */



#endif //MYLEETCODE_LINKEDLISTRANDOMNODE_HPP
