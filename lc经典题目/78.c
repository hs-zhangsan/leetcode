/*、
    迭代法实现子集枚举
    思路与算法：
    记原序列中元素的总数为 n。
    原序列中的每个数字 a_i 的状态可能有两种，即「在子集中」和「不在子集中」。
    我们用 1 表示「在子集中」，0 表示不在子集中，那么每一个子集可以对应一个长度为 n 的 0/1 序列，第 i 位表示 a_i 是否在子集中。
    例如，n = 3，a = {5, 2, 9} 时：
        0/1 序列        子集        0/1 序列对应的二进制数
        000             {}          0
        001             {9}         1
        010             {2}         2
        011             {2,9}       3
        100             {5}         4
        101             {5,9}       5
        110             {5,2}       6
        111             {5,2,9}     7
    可以发现 0/1 序列对应的二进制数正好从 0 到 2^n - 1。
    我们可以枚举 mask∈[0,2^n ?1]，mask 的二进制表示是一个 0/1 序列，我们可以按照这个 0/1 序列在原集合当中取数。
    当我们枚举完所有 2^n 个 mask，我们也就能构造出所有的子集。
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