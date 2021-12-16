/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* singleNumbers(int* nums, int numsSize, int* returnSize){
    //������Ԫ�ؽ���������㣬���Ϊ����ͬ���ֵ����� mask��
    int mask = 0;
    for (int i = 0; i < numsSize; i++) {
        mask ^= nums[i];
    }

    //�ҵ� mask �Ĳ�Ϊ 0 �����λ��
    int div = 1;
    while ((div & mask) == 0) {
        div <<= 1;
    }
 
    //���ղ�Ϊ 0 �����λ��Ϊ���顣
    //����ͬ�����ֱ��������У���������ͬ���������������ͬһ�顣
    //��ÿһ��ֱ������ͼ��õ�����ͬ�����֡�
    int a = 0, b = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] & div) {
            a ^= nums[i];
        } else {
            b ^= nums[i];
        }
    }

    *returnSize = 2;
    int* ret = malloc(sizeof(int) * 2);
    ret[0] = a;
    ret[1] = b;

    return ret;
}