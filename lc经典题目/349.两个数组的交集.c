/*
 * @lc app=leetcode.cn id=349 lang=c
 *
 * [349] 两个数组的交集
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int cmp(void* a, void* b) {
    return *(int*)a - *(int*)b;
}

int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    qsort(nums1, nums1Size, sizeof(int), cmp);
    qsort(nums2, nums2Size, sizeof(int), cmp);
    *returnSize = 0;
    int index1 = 0, index2 = 0;
    int* ans = malloc(sizeof(int) * nums1Size);
    while (index1 < nums1Size && index2 < nums2Size) {
        if (nums1[index1] == nums2[index2]) {
            if (!(*returnSize) || nums1[index1] != ans[(*returnSize) - 1]) {
                ans[(*returnSize)++] = nums1[index1];
            }
            index1++;
            index2++;
        } else if (nums1[index1] < nums2[index2]) {
            index1++;
        } else {
            index2++;
        }
    }
    return ans;
}
// @lc code=end

