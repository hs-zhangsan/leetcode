/*
    ����ʹ������ָ�룬fast �� slow��������ʼ��λ�������ͷ����
    ���slow ָ��ÿ������ƶ�һ��λ�ã��� fast ָ������ƶ�����λ�á�
    ��������д��ڻ����� fast ָ�����ս��ٴ��� slow ָ���ڻ���������
    
    �������л��ⲿ�ֵĳ���Ϊ a��slow ָ����뻷�������� b �ľ����� fast ������
    ��ʱ��fast ָ���Ѿ������˻��� n Ȧ��������߹����ܾ���Ϊ a + n(b + c) + b = a + (n + 1)b + nc��
    
    �������⣬����ʱ�̣�fast ָ���߹��ľ��붼Ϊ slow ָ��� 2 ����
    ��ˣ�������
        a + (n + 1)b + nc = 2(a + b) ? a = c + (n - 1)(b + c)
    
    ���� a = c + (n - 1)(b + c)a = c + (n ? 1)(b + c) �ĵ�����ϵ�����ǻᷢ�֣�
        �������㵽�뻷��ľ������ n ? 1 Ȧ�Ļ�����ǡ�õ��ڴ�����ͷ�����뻷��ľ��롣
        
    ��ˣ������� slow �� fast ����ʱ�������ٶ���ʹ��һ��ָ�� ptr��
    ��ʼ����ָ������ͷ����
    ������� slow ÿ������ƶ�һ��λ�á�
    ���գ����ǻ����뻷��������
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) {
    struct ListNode* fast = head, * slow = head;
    do {
        if (fast == NULL || fast->next == NULL) {
            return NULL;
        }

        fast = fast->next->next;
        slow = slow->next;
    } while (fast != slow);

    struct ListNode* ptr = head;
    while (ptr != fast) {
        ptr = ptr->next;
        fast = fast->next;
    }

    return fast;
}