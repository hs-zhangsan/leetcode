struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    //设置哑结点
    struct ListNode* dummyHead = malloc(sizeof(struct ListNode));
    dummyHead->next = head;
    //设置双指针
    struct ListNode* fast = dummyHead;
    struct ListNode* slow = dummyHead;
    //fast 先走 N+1 步
    while (n--) {
        fast = fast->next;
    }
    fast = fast->next;
    //fast 和 slow 同时向后移动直到 fast 指向 NULL
    while (fast) {
        fast = fast->next;
        slow = slow->next;
    }
    //删除结点
    slow->next = slow->next->next;
    //注意返回的是 dummy->next 而不是 head
    return dummyHead->next;
}