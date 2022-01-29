/*
 * @lc app=leetcode.cn id=46 lang=c
 *
 * [46] 全排列
 */

// @lc code=start


/**
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int* path;
int pathTop;
int** result;
int resultTop;

void backtracking(int* nums, int numsSize, int* used) {
    if (pathTop == numsSize) {
        int* tempPath = malloc(sizeof(int) * pathTop);
        for (int i = 0; i < pathTop; i++) {
            tempPath[i] = path[i];
        }
        result[resultTop++] = tempPath;
        return;
    }

    for (int i = 0; i < numsSize; i++) {
        if (used[i]) {
            continue;
        }

        used[i] = 1;
        path[pathTop++] = nums[i];
        backtracking(nums, numsSize, used);
        pathTop--;
        used[i] = 0;
    }
}

int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    path = malloc(sizeof(int) * numsSize);
    result = malloc(sizeof(int*) * 1000);
    int* used = malloc(sizeof(int) * numsSize);
    for (int i = 0; i < numsSize; i++) {
        used[i] = 0;
    }
    pathTop = resultTop = 0;

    backtracking(nums, numsSize, used);

    *returnSize = resultTop;
    *returnColumnSizes = malloc(sizeof(int) * resultTop);
    for (int i = 0; i < resultTop; i++) {
        (*returnColumnSizes)[i] = numsSize;
    }
    return result;
}
// @lc code=end

