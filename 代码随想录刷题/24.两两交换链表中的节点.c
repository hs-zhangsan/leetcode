/*
 * @lc app=leetcode.cn id=24 lang=c
 *
 * [24] 两两交换链表中的节点
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head){
    struct ListNode* dummyHead = malloc(sizeof(struct ListNode));
    dummyHead->next = head;
    struct ListNode* curr = dummyHead;
    while (curr->next && curr->next->next) {
        struct ListNode* temp1 = curr->next;
        struct ListNode* temp2 = curr->next->next->next;

        curr->next = curr->next->next;
        curr->next->next = temp1;
        curr->next->next->next = temp2;

        curr = curr->next->next;
    }
    return dummyHead->next;
}
// @lc code=end

