/*
 * @lc app=leetcode.cn id=215 lang=c
 *
 * [215] 数组中的第K个最大元素
 */

// @lc code=start
int cmp(void* a, void* b) {
    return *(int*)a - *(int*)b;
}

int findKthLargest(int* nums, int numsSize, int k){
    qsort(nums, numsSize, sizeof(int), cmp);
    return nums[numsSize - k];
}
// @lc code=end

