/*
 * @lc app=leetcode.cn id=206 lang=c
 *
 * [206] 反转链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
//双指针法
struct ListNode* reverseList(struct ListNode* head){
    struct ListNode* curr = head;
    struct ListNode* prew = NULL;
    while (curr) {
        //保存下一个结点
        struct ListNode* temp = curr->next;
        //反转结点
        curr->next = prew;
        //更新 curr 和 prew 指针
        prew = curr;
        curr = temp;
    }
    return prew;
}

//递归（从前向后反转指针指向）
struct ListNode* reverse(struct ListNode* curr, struct ListNode* prew) {
    if (!curr) {
        return prew;
    }
    //可以与双指针法对比，其实逻辑是一样的，只是用递归实现而已
    struct ListNode* temp = curr->next;
    curr->next = prew;
    return reverse(temp, curr);
}
struct ListNode* reverseList(struct ListNode* head){
    return reverse(head, NULL);
}

//递归（从后向前反转指针指向）
struct ListNode* reverseList(struct ListNode* head){
    //递归结束条件判断
    if (!head || !head->next) {
        return head;
    }

    //调用递归，反转第二个结点后的结点
    struct ListNode* newHead = reverseList(head->next);
    //反转头结点与第二个结点
    head->next->next = head;
    //此时 head 是尾结点，尾结点需要指向 NULL
    head->next = NULL;

    return newHead;
}
// @lc code=end

