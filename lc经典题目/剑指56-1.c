/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* singleNumbers(int* nums, int numsSize, int* returnSize){
    //对所有元素进行异或运算，结果为两不同数字的异或和 mask。
    int mask = 0;
    for (int i = 0; i < numsSize; i++) {
        mask ^= nums[i];
    }

    //找到 mask 的不为 0 的最低位。
    int div = 1;
    while ((div & mask) == 0) {
        div <<= 1;
    }
 
    //按照不为 0 的最低位分为两组。
    //两不同的数分别在两组中，且其他相同的两个数都会分在同一组。
    //对每一组分别求异或和即得到两不同的数字。
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