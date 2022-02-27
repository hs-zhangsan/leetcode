struct ListNode *detectCycle(struct ListNode *head) {
    struct ListNode* fast = head;
    struct ListNode* slow = head;
    while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow) {
            while (fast != head) {
                fast = fast->next;
                head = head->next;
            }
            return fast;
        }
    }
    return NULL;
}