/*
 * @lc app=leetcode.cn id=142 lang=c
 *
 * [142] 环形链表 II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) {
    struct ListNode* fast = head;
    struct ListNode* slow = head;
    while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow) {
            slow = head;
            while (fast != slow) {
                fast = fast->next;
                slow = slow->next;
            }
            return fast;
        }
    }
    return NULL;
}
// @lc code=end

