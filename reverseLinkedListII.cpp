//
// Created by 李研 on 2019/8/15.
//

#include "MyLeetCode.h"

/*
 * 92. Reverse Linked List II
 * https://leetcode.com/problems/reverse-linked-list-ii/
 */

ListNode *MyLeetCode::reverseBetween(ListNode *head, int m, int n) {
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    ListNode *prev = nullptr, *back;
    ListNode *prev_m = dummy, *back_n;
    int count = 0;
    while (1) {
        ++count;
        if (count < m) {
            prev_m = head;
            head = head->next;
            continue;
        }
        if (count == m) { back_n = head; }
        if (count == n+1) {
            back_n->next = head;
            prev_m->next = prev;
            break;
        }
        back = head->next;
        head->next = prev;
        prev = head;
        head = back;
    }
    return dummy->next;
}