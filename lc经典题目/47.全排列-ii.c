/*
 * @lc app=leetcode.cn id=47 lang=c
 *
 * [47] 全排列 II
 */

// @lc code=start
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int* path;
int pathTop;
int** result;
int resultTop;
int* used;

void backtracking(int* used, int* nums, int numsSize) {
    if (pathTop == numsSize) {
        int* tempPath = malloc(sizeof(int) * pathTop);
        for (int i = 0; i < pathTop; i++) {
            tempPath[i] = path[i];
        }
        result[resultTop++] = tempPath;
    }

    for (int i = 0; i < numsSize; i++) {
        if (used[i] || (i != 0 && nums[i] == nums[i - 1] && used[i - 1] == 0)) {
            continue;
        }
        used[i] = 1;
        path[pathTop++] = nums[i];
        backtracking(used, nums, numsSize);
        used[i] = 0;
        pathTop--;
    }
}

int cmp(void* a, void* b) {
    return *((int*)a) - *((int*)b);
}

int** permuteUnique(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    qsort(nums, numsSize, sizeof(int), cmp);
    pathTop = resultTop = 0;
    path = malloc(sizeof(int) * numsSize);
    result = malloc(sizeof(int*) * 1000);
    used = malloc(sizeof(int) * numsSize);
    for (int i = 0; i < numsSize; i++) {
        used[i] = 0;
    }

    backtracking(used, nums, numsSize);

    *returnSize = resultTop;
    *returnColumnSizes = malloc(sizeof(int) * resultTop);
    for (int i = 0; i < resultTop; i++) {
        (*returnColumnSizes)[i] = numsSize;
    }
    return result;
}
// @lc code=end

