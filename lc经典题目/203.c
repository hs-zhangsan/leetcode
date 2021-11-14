/*
    �����õ����ķ���ɾ�����������нڵ�ֵ�����ض�ֵ�Ľڵ㡣
    ���ݹ�������
    �� temp ��ʾ��ǰ�ڵ㡣
    ��� temp ����һ���ڵ㲻Ϊ������һ���ڵ�Ľڵ�ֵ���ڸ����� val������Ҫɾ����һ���ڵ㡣
    ɾ����һ���ڵ����ͨ����������ʵ�֣�
        temp.next = temp.next.next
    ��� temp ����һ���ڵ�Ľڵ�ֵ�����ڸ����� val��������һ���ڵ㣬�� temp �ƶ�����һ���ڵ㼴�ɡ�
    �� temp ����һ���ڵ�Ϊ��ʱ�����������������ʱ���нڵ�ֵ���� val �Ľڵ㶼��ɾ����
    ����ʵ�ַ��棬���������ͷ�ڵ� head �п�����Ҫ��ɾ������˴����ƽڵ� dummyHead��
    �� temp = dummyHead��Ȼ������������ɾ��������
    ���շ��� dummyHead.next ��Ϊɾ���������ͷ�ڵ㡣
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* removeElements(struct ListNode* head, int val){
    struct ListNode* dummyHead = malloc(sizeof(struct ListNode));
    dummyHead->next = head;
    struct ListNode* temp = dummyHead;

    while (temp->next != NULL) {
        if (temp->next->val == val) {
            temp->next = temp->next->next;
        }
        else {
            temp = temp->next;
        }
    }
    return dummyHead->next;
}