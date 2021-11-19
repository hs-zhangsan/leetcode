/*
    ʹ��˫ָ��ķ��������Խ��ռ临�ӶȽ��� O(1)��
    ֻ�е����� headA �� headB ����Ϊ��ʱ����������ſ����ཻ��
    ��������ж����� headA �� headB �Ƿ�Ϊ�գ�
    �������������һ������Ϊ�գ�����������һ�����ཻ������ null��
    ������ headA �� headB ����Ϊ��ʱ����������ָ�� pA �� pB��
    ��ʼʱ�ֱ�ָ�����������ͷ�ڵ� headA �� headB��Ȼ������ָ�����α������������ÿ���ڵ㡣
    �����������£�
        ÿ��������Ҫͬʱ����ָ�� pA �� pB��
        ���ָ�� pA ��Ϊ�գ���ָ�� pA �Ƶ���һ���ڵ㣻
        ���ָ�� pB ��Ϊ�գ���ָ�� pB �Ƶ���һ���ڵ㡣
        ���ָ�� pA Ϊ�գ���ָ�� pA �Ƶ����� headB ��ͷ�ڵ㣻
        ���ָ�� pB Ϊ�գ���ָ�� pB �Ƶ����� headA ��ͷ�ڵ㡣
        ��ָ�� pA �� pB ָ��ͬһ���ڵ���߶�Ϊ��ʱ����������ָ��Ľڵ���� null��

    ��������������֤����֤�������ԡ�
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    if (headA == NULL || headB == NULL) {
        return NULL;
    }

    struct ListNode* pA = headA, * pB = headB;
    while (pA != pB) {
        pA = (pA == NULL ? headB : pA->next);
        pB = (pB == NULL ? headA : pB->next);
    }

    return pA;
}