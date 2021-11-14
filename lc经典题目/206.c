/*
    假设链表为 1→2→3→?，我们想要把它改成 ?←1←2←3。
    在遍历链表时，将当前节点的 next 指针改为指向前一个节点。
    由于节点没有引用其前一个节点，因此必须事先存储其前一个节点。
    在更改引用之前，还需要存储后一个节点。
    最后返回新的头引用。
*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* reverseList(struct ListNode* head){
    struct ListNode* prew = NULL;
    struct ListNode* curr = head;
    struct ListNode* next;
    while (curr) {
        next = curr->next;      //储存后一个节点
        curr->next = prew;      //当前节点的 next 指向前一个节点
        prew = curr;
        curr = next;
    }
    return prew;
}