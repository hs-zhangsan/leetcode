/*
    �Ǹ�������ĳ���Ϊ n��ע�⵽�������ƶ��Ĵ��� k �� n ʱ�����ǽ���Ҫ�����ƶ� k mod n �μ��ɡ�
    ��Ϊÿ n ���ƶ������������Ϊԭ״��
    �������ǿ���֪��������������һ���ڵ�Ϊԭ����ĵ� (n - 1) - (k mod n) ���ڵ㣨�� 0 ��ʼ��������
    ���������ǿ����Ƚ��������������ӳɻ���Ȼ��ָ��λ�öϿ���
    ��������У��������ȼ��������ĳ��� n�����ҵ��������ĩβ�ڵ㣬������ͷ�ڵ�������
    �����͵õ��˱պ�Ϊ��������
    Ȼ�������ҵ�����������һ���ڵ㣨��ԭ����ĵ� (n - 1) - (k mod n) ���ڵ㣩��
    ����ǰ�պ�Ϊ��������Ͽ������ɵõ���������Ҫ�Ľ����
    �ر�أ��������Ȳ����� 1������ k Ϊ n �ı���ʱ����������ԭ������ͬ��������������κδ���
*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* rotateRight(struct ListNode* head, int k){
    if (k == 0 || head == NULL || head->next == NULL) {
        return head;
    }

    int n = 1;
    struct ListNode* iter = head;
    while (iter->next) {
        iter = iter->next;
        n++;
    }

    int add = n - k % n;
    if (add == n) {
        return head;
    }

    iter->next = head;
    while (add--) {
        iter = iter->next;
    }

    struct ListNode* ret = iter->next;
    iter->next = NULL;
    return ret;
}