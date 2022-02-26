struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    //�����ƽ��
    struct ListNode* dummyHead = malloc(sizeof(struct ListNode));
    dummyHead->next = head;
    //����˫ָ��
    struct ListNode* fast = dummyHead;
    struct ListNode* slow = dummyHead;
    //fast ���� N+1 ��
    while (n--) {
        fast = fast->next;
    }
    fast = fast->next;
    //fast �� slow ͬʱ����ƶ�ֱ�� fast ָ�� NULL
    while (fast) {
        fast = fast->next;
        slow = slow->next;
    }
    //ɾ�����
    slow->next = slow->next->next;
    //ע�ⷵ�ص��� dummy->next ������ head
    return dummyHead->next;
}