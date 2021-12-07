/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    struct ListNode* fast = head, * slow = head;
    
    do {
        if (fast == NULL || fast->next == NULL) {
            return false;
        }
        fast = fast->next->next;
        slow = slow->next;
    } while (fast != slow);

    return true;
}