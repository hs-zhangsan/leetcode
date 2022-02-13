/*
 * @lc app=leetcode.cn id=19 lang=c
 *
 * [19] 删除链表的倒数第 N 个结点
 */

// @lc code=start
struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode* dummyHead = malloc(sizeof(struct ListNode));
    dummyHead->next = head;

    struct ListNode* fast = dummyHead;
    struct ListNode* slow = dummyHead;
    while (n--) {
        fast = fast->next;
    }
    fast = fast->next;

    while (fast) {
        fast = fast->next;
        slow = slow->next;
    }
    slow->next = slow->next->next;

    return dummyHead->next;
}
// @lc code=end

