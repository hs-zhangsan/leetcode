struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    //�����������Ȳ�
    struct ListNode* tempA = headA;
    struct ListNode* tempB = headB;
    int lenA = 0, lenB = 0;
    while (tempA) {
        lenA++;
        tempA = tempA->next;
    }
    while (tempB) {
        lenB++;
        tempB = tempB->next;
    }
    int gap;
    if (lenA > lenB) {
        gap = lenA - lenB;
        tempA = headA;
        tempB = headB;
    } else {
        gap = lenB- lenA;
        tempA = headB;
        tempB = headA;
    }
    //���Ƚϳ��������ƶ� gap ����ʹ������β������
    while (gap--) {
        tempA = tempA->next;
    }
    //���ҵ������򷵻أ����򷵻ؿ�ָ��
    while (tempA) {
        if (tempA == tempB) {
            return tempA;
        }
        tempA = tempA->next;
        tempB = tempB->next;
    }
    return NULL;
}