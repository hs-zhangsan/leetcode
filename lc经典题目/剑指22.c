/*
    ����ָ���˼�롣
    ���ǽ���һ��ָ�� fast ָ������ĵ� k + 1 ���ڵ㣬�ڶ���ָ�� slow ָ������ĵ�һ���ڵ㣬
    ��ʱָ�� fast �� slow ����֮��պü�� k ���ڵ㡣
    ��ʱ����ָ��ͬ������ߣ�����һ��ָ�� fast �ߵ������β���սڵ�ʱ��
     ���ʱ slow ָ��պ�ָ������ĵ�����k���ڵ㡣
     �������Ƚ� fast ָ�������ͷ�ڵ㣬Ȼ������� k �������ʱ fast ָ��պ�ָ������ĵ� k + 1 ���ڵ㡣
     �������Ƚ� slow ָ�������ͷ�ڵ㣬ͬʱ slow �� fast ͬ������ߣ�
     �� fast ָ��ָ�������β���սڵ�ʱ�����ʱ���� low ��ָ��Ľڵ㼴�ɡ�
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* getKthFromEnd(struct ListNode* head, int k){
    struct ListNode* fast = head, * slow = head;
    while (k--) {
        fast = fast->next;
    }
    while (fast) {
        fast = fast->next;
        slow = slow->next;
    }

    return slow;
}