//
// Created by 李研 on 2019/8/16.
//

#include "MyLeetCode.h"

/*
 * 61. Rotate List
 * https://leetcode.com/problems/rotate-list/
 */

ListNode* MyLeetCode::rotateRight(ListNode* head, int k) {
    if (k==0 || head == nullptr) { return head; }
    map<int, ListNode*> hashMap;
    int count = 0;
    while (1) {
        ++count;
        hashMap[count] = head;
        if (head->next == nullptr) {
            head->next = hashMap[1];
            break;
        }
        head = head->next;
    }
    k %= count;
    ListNode* new_head = hashMap[count-k]->next;
    hashMap[count-k]->next = nullptr;
    return new_head;
}