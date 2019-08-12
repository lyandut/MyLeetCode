//
// Created by 李研 on 2019/8/11.
//

#include "MyLeetCode.h"

/*
 * 206. Reverse Linked List
 * https://leetcode.com/problems/reverse-linked-list/
 */

/// 迭代
//ListNode *MyLeetCode::reverseList(ListNode *head) {
//    ListNode *prev = nullptr;
//    ListNode *back;
//    while(head) {
//        back = head->next;
//        head->next = prev;
//        prev = head;
//        head = back;
//    }
//    return prev;
//}

/// 递归一：
//ListNode* _reverseList(ListNode *head, ListNode *prev = nullptr){
//    if (head == nullptr) { return prev; }
//    ListNode *back = head->next;
//    head->next = prev;
//    return _reverseList(back, head);
//}
//
//ListNode* MyLeetCode::reverseList(ListNode *head) {
//    return _reverseList(head);
//}


/// 递归二：
ListNode* MyLeetCode::reverseList(ListNode *head) {
    if(head == nullptr || head->next == nullptr) { return head; }
    ListNode *new_head = reverseList(head->next);
    head->next->next = head;
    head->next = nullptr;
    return new_head;
}



