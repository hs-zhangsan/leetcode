/*��
    ������ʵ���Ӽ�ö��
    ˼·���㷨��
    ��ԭ������Ԫ�ص�����Ϊ n��
    ԭ�����е�ÿ������ a_i ��״̬���������֣��������Ӽ��С��͡������Ӽ��С���
    ������ 1 ��ʾ�����Ӽ��С���0 ��ʾ�����Ӽ��У���ôÿһ���Ӽ����Զ�Ӧһ������Ϊ n �� 0/1 ���У��� i λ��ʾ a_i �Ƿ����Ӽ��С�
    ���磬n = 3��a = {5, 2, 9} ʱ��
        0/1 ����        �Ӽ�        0/1 ���ж�Ӧ�Ķ�������
        000             {}          0
        001             {9}         1
        010             {2}         2
        011             {2,9}       3
        100             {5}         4
        101             {5,9}       5
        110             {5,2}       6
        111             {5,2,9}     7
    ���Է��� 0/1 ���ж�Ӧ�Ķ����������ô� 0 �� 2^n - 1��
    ���ǿ���ö�� mask��[0,2^n ?1]��mask �Ķ����Ʊ�ʾ��һ�� 0/1 ���У����ǿ��԰������ 0/1 ������ԭ���ϵ���ȡ����
    ������ö�������� 2^n �� mask������Ҳ���ܹ�������е��Ӽ���
*/


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int** ans = malloc(sizeof(int*) * (1 << numsSize));
    *returnColumnSizes = malloc(sizeof(int) * (1 << numsSize));
    *returnSize = 1 << numsSize;
    int t[numsSize];
    
    for (int mask = 0; mask < (1 << numsSize); mask++) {
        int tSize = 0;
        for (int i = 0; i < numsSize; i++) {
            if (mask & (1 << i)) {
                t[tSize++] = nums[i];
            }
        }

        int* tem = malloc(sizeof(int) * tSize);
        memcpy(tem, t, sizeof(int) * tSize);
        (*returnColumnSizes)[mask] = tSize;
        ans[mask] = tem;
    }

    return ans;
}