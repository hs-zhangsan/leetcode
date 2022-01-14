/*
 * @lc app=leetcode.cn id=23 lang=c
 *
 * [23] 合并K个升序链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* meregTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* head = malloc(sizeof(struct ListNode));
    struct ListNode* diff = head;
    while (l1 && l2) {
        if (l1->val <= l2->val) {
            diff->next = l1;
            l1 = l1->next;
        } else {
            diff->next = l2;
            l2 = l2->next;
        }
        diff = diff->next;
    }
    diff->next = l1 ? l1 : l2;
    return head->next;
}
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
    if (!listsSize) {
        return NULL;
    }

    struct ListNode* l1, * l2;
    l1 = lists[0];
    for (int i = 1; i < listsSize; i++) {
        l2 = lists[i];
        l1 = meregTwoLists(l1, l2);
    }

    return l1;
}
// @lc code=end

