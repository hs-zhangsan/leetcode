/*
    ����ڵ��ϲ�

    �������Ϊ�գ���ֱ�ӷ�������

    ����ԭʼ����ÿ���ڵ㶼�������ڵ��ż���ڵ㡣
    ͷ�ڵ��������ڵ㣬ͷ�ڵ�ĺ�һ���ڵ���ż���ڵ㣬���ڽڵ����ż�Բ�ͬ��
    ��˿��Խ������ڵ��ż���ڵ��������������ż������Ȼ��ż��������������������֮�󣬺ϲ��������Ϊ�������
    
    ԭʼ�����ͷ�ڵ� head Ҳ�����������ͷ�ڵ��Լ���������ͷ�ڵ㣬head �ĺ�һ���ڵ���ż�������ͷ�ڵ㡣
    �� evenHead = head.next���� evenHead ��ż�������ͷ�ڵ㡣

    ά������ָ�� odd �� even �ֱ�ָ�������ڵ��ż���ڵ㣬��ʼʱ odd = head��even = evenHead��
    ͨ�������ķ�ʽ�������ڵ��ż���ڵ�������������ÿһ�����ȸ��������ڵ㣬Ȼ�����ż���ڵ㡣
        ���������ڵ�ʱ�������ڵ�ĺ�һ���ڵ���Ҫָ��ż���ڵ�ĺ�һ���ڵ㣬
        ����� odd.next = even.next��Ȼ���� odd = odd.next����ʱ odd ��� even �ĺ�һ���ڵ㡣
        ����ż���ڵ�ʱ��ż���ڵ�ĺ�һ���ڵ���Ҫָ�������ڵ�ĺ�һ���ڵ㣬
        ����� even.next = odd.next��Ȼ���� even = even.next����ʱ even ��� odd �ĺ�һ���ڵ㡣

    ����������֮�󣬼�����˶�һ�������ڵ��һ��ż���ڵ�ķ��롣
    �ظ�����������ֱ��ȫ���ڵ������ϡ�
    ȫ���ڵ������ϵ������� even Ϊ�սڵ���� even.next Ϊ�սڵ㣬��ʱ odd ָ�����һ�������ڵ㣨��������������һ���ڵ㣩��
    
    ����� odd.next = evenHead����ż��������������������֮�󣬼���������������ż������ĺϲ�����������ͷ�ڵ���Ȼ�� head��
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* oddEvenList(struct ListNode* head){
    if (head == NULL) {
        return head;
    }

    struct ListNode* evenHead = head->next;
    struct ListNode* odd = head, * even = head->next;

    while (even != NULL && even->next != NULL) {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }
    odd->next = evenHead;
    
    return head;
}