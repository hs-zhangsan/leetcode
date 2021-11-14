/*
    ��������Ϊ 1��2��3��?��������Ҫ�����ĳ� ?��1��2��3��
    �ڱ�������ʱ������ǰ�ڵ�� next ָ���Ϊָ��ǰһ���ڵ㡣
    ���ڽڵ�û��������ǰһ���ڵ㣬��˱������ȴ洢��ǰһ���ڵ㡣
    �ڸ�������֮ǰ������Ҫ�洢��һ���ڵ㡣
    ��󷵻��µ�ͷ���á�
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
        next = curr->next;      //�����һ���ڵ�
        curr->next = prew;      //��ǰ�ڵ�� next ָ��ǰһ���ڵ�
        prew = curr;
        curr = next;
    }
    return prew;
}