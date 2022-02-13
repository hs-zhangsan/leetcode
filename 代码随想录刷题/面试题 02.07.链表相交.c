struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    //计算两链表长度差
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
    //长度较长的链表移动 gap 步，使两链表尾部对其
    while (gap--) {
        tempA = tempA->next;
    }
    //若找到交点则返回，否则返回空指针
    while (tempA) {
        if (tempA == tempB) {
            return tempA;
        }
        tempA = tempA->next;
        tempB = tempB->next;
    }
    return NULL;
}