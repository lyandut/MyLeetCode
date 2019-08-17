//
// Created by 李研 on 2019/8/17.
//

#include "MyLeetCode.h"

/*
 * 24. Swap Nodes in Pairs
 * https://leetcode.com/problems/swap-nodes-in-pairs/
 */

/// 递归
//ListNode* MyLeetCode::swapPairs(ListNode* head) {
//    if (head == nullptr || head->next == nullptr) { return head; }
//    ListNode *prev = head;
//    ListNode *back = head->next;
//    prev->next = swapPairs(back->next);
//    back->next = prev;
//    return back;
//}

/// 迭代
ListNode* MyLeetCode::swapPairs(ListNode* head) {
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    ListNode *prev = dummy, *back; // 前驱后继
    while (head && head->next) {
        back = head->next->next;   // 记录后继
        prev->next = head->next;
        head->next->next = head;
        head->next = back;
        prev = head;               // 记录前驱
        head = back;
    }
    return dummy->next;
}