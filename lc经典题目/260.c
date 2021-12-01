/*
    �������
    �� xorsum Ϊ�������ֵ� xor �ͣ��� xorsum=a[0]�� a[1] �� a[2]...��
    �� x��y Ϊ����ֻ����һ�ε����֣���ô xorsum һ����������ֻ����һ�ε����ֵ����ֵ���� xorsum = x �� y��
    ���� xorsum ��ÿһ��������λ���� xorsum �Ķ�����λȫ������0���� x��y ֻ����һ����Υ����
    ��� xorsum �Ķ�����λ��һ�����ڵ��� 1 �Ķ�����λ������ x��y ����ȵĶ�����λ��
    ���Լ�¼ xorsum ���� 1 �Ķ�����λ�����Ը������������λ�Ĳ�ͬ���� x��y ��Ϊ���飬������� x��y��

    PS��xorsum Ҫ�� long ���Ͷ������� int ���ͣ���Ҳ��֪��Ϊʲô������
        ������ϸ翴����֪��������ҡ�(��������)��
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* singleNumber(int* nums, int numsSize, int* returnSize){
    long xorsum = 0;
    for (int i = 0; i < numsSize; i++) {
        xorsum ^= nums[i];
    }

    int* ans = malloc(sizeof(int) * 2);
    ans[0] = 0;
    ans[1] = 0;
    *returnSize = 2;
    long mask = xorsum & (-xorsum);
    for (int i = 0; i < numsSize; i++) {
        if ((nums[i] & mask) == mask) {
            ans[0] ^= nums[i];
        } else {
            ans[1] ^= nums[i];
        }
    }

    return ans;
}