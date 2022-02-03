/*
 * @lc app=leetcode.cn id=977 lang=c
 *
 * [977] 有序数组的平方
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortedSquares(int* nums, int numsSize, int* returnSize){
    int* result = malloc(sizeof(int) * numsSize);

    int i = 0, j = numsSize - 1, k = numsSize - 1;
    while (k >= 0) {
        if (nums[i] * nums[i] > nums[j] * nums[j]) {
            result[k--] = nums[i] * nums[i];
            i++;
        } else {
            result[k--] = nums[j] * nums[j];
            j--;
        }
    }

    *returnSize = numsSize;
    return result;
}
// @lc code=end

