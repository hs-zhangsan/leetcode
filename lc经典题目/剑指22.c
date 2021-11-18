/*
    快慢指针的思想。
    我们将第一个指针 fast 指向链表的第 k + 1 个节点，第二个指针 slow 指向链表的第一个节点，
    此时指针 fast 与 slow 二者之间刚好间隔 k 个节点。
    此时两个指针同步向后走，当第一个指针 fast 走到链表的尾部空节点时，
     则此时 slow 指针刚好指向链表的倒数第k个节点。
     我们首先将 fast 指向链表的头节点，然后向后走 k 步，则此时 fast 指针刚好指向链表的第 k + 1 个节点。
     我们首先将 slow 指向链表的头节点，同时 slow 与 fast 同步向后走，
     当 fast 指针指向链表的尾部空节点时，则此时返回 low 所指向的节点即可。
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* getKthFromEnd(struct ListNode* head, int k){
    struct ListNode* fast = head, * slow = head;
    while (k--) {
        fast = fast->next;
    }
    while (fast) {
        fast = fast->next;
        slow = slow->next;
    }

    return slow;
}