/* ˫ָ�뷨
struct ListNode* reverseList(struct ListNode* head){
    struct ListNode* prew = NULL;
    struct ListNode* curr = head;
    struct ListNode* temp;
    while (curr) {
        temp = curr->next;
        curr->next = prew;
        prew = curr;
        curr = temp;
    }
    return prew;
}
 */

// �ݹ鷨
struct ListNode* reverseList(struct ListNode* head) {
    if (!head || !head->next) {
        return head;
    }

    struct ListNode* last = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;
    return last;
}