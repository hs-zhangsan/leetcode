/*
    异或运算
    设 xorsum 为所有数字的 xor 和，即 xorsum=a[0]⊕ a[1] ⊕ a[2]...。
    设 x，y 为两个只出现一次的数字，那么 xorsum 一定等于两个只出现一次的数字的异或值，即 xorsum = x ⊕ y。
    考虑 xorsum 的每一个二进制位，若 xorsum 的二进制位全部等于0，与 x，y 只出现一次相违背，
    因此 xorsum 的二进制位，一定存在等于 1 的二进制位，即是 x，y 不相等的二进制位。
    可以记录 xorsum 等于 1 的二进制位，可以根据这个二进制位的不同，将 x，y 分为两组，进而求出 x，y。

    PS：xorsum 要用 long 类型而不能用 int 类型，我也不知道为什么。。。
        如果有老哥看到且知道请告诉我。(～￣▽￣)～
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