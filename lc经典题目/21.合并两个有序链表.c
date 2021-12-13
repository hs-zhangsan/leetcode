/*
 * @lc app=leetcode.cn id=21 lang=c
 *
 * [21] 合并两个有序链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    struct ListNode* list3 = malloc(sizeof(struct ListNode));
    struct ListNode* ret = list3;
    while (list1 && list2) {
        if (list1->val <= list2->val) {
            list3->next = list1;
            list1 = list1->next;
        } else {
            list3->next = list2;
            list2 = list2->next;
        }
        list3 = list3->next;
    }
    
    if (!list1) {
        list3->next = list2;
    } else if (!list2) {
        list3->next = list1;
    }

    return ret->next;
}
// @lc code=end

