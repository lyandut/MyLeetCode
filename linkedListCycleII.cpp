//
// Created by 李研 on 2019/8/12.
//

#include "MyLeetCode.h"

/*
 * 142. Linked List Cycle II
 * https://leetcode.com/problems/linked-list-cycle-ii/
 */

ListNode* MyLeetCode::detectCycle(ListNode *head) {
    ListNode *fast = head, *slow = head;
    while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow) {
            fast = head;
            while (fast != slow) {
               fast = fast->next;
               slow = slow->next;
            }
            return fast;
        }
    }
    return nullptr;
}