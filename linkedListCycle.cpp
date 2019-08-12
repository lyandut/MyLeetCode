//
// Created by 李研 on 2019/8/11.
//

#include "MyLeetCode.h"

/*
 * 141. Linked List Cycle
 * https://leetcode.com/problems/linked-list-cycle/
 */

bool MyLeetCode::hasCycle(ListNode *head) {
    ListNode *fast = head, *slow = head;
    while(fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow) { return true; }
    }
    return false;
}