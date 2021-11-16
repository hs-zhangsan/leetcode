/*
    ֱ����˵����ֻ��ά���������� small �� large ���ɣ�small ����˳��洢����С�� xx �Ľڵ㣬
    large ����˳��洢���д��ڵ��� x �Ľڵ㡣
    ������ԭ���������ֻҪ�� small ����β�ڵ�ָ�� large �����ͷ�ڵ㼴����ɶ�����ķָ���
    Ϊ��ʵ������˼·�������� smallHead �� largeHead �ֱ�Ϊ����������ƽڵ㣬
    �����ǵ� next ָ��ָ�������ͷ�ڵ㣬��������Ŀ����Ϊ�˸�����ش���ͷ�ڵ�Ϊ�յı߽�������
    ͬʱ�� small �� large �ڵ�ָ��ǰ�����ĩβ�ڵ㡣
    ��ʼʱ smallHead = small,largeHead = large��
    ��󣬴�ǰ������������жϵ�ǰ����Ľڵ�ֵ�Ƿ�С�� x�����С�ھͽ� small �� next ָ��ָ��ýڵ㣬
    ���� large �� next ָ��ָ��ýڵ㡣
    �������������ǽ� large �� next ָ���ÿգ�������Ϊ��ǰ�ڵ㸴�õ���ԭ����Ľڵ㣬
    ���� next ָ�����ָ��һ��С�� x �Ľڵ㣬������Ҫ�ж�������á�
    ͬʱ�� small �� next ָ��ָ�� largeHead �� next ָ��ָ��Ľڵ㣬�����������ϵ� large �����ͷ�ڵ㡣
    ��󷵻� smallHead �� next ָ�뼴Ϊ����Ҫ��Ĵ𰸡�
*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* partition(struct ListNode* head, int x){
    struct ListNode* large = malloc(sizeof(struct ListNode));
    struct ListNode* small = malloc(sizeof(struct ListNode));
    struct ListNode* largeHead = large, * smallHead = small;

   while (head) {
       if (head->val >= x) {
           large->next = head;
           large = large->next;
       }
       else {
           small->next = head;
           small = small->next;
       }
       head = head->next;
   }
   large->next = NULL;
   small->next = largeHead->next;

   return smallHead->next;
}