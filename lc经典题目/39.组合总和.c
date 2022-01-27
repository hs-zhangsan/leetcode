/*
 * @lc app=leetcode.cn id=39 lang=c
 *
 * [39] 组合总和
 */

// @lc code=start


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int* path;
int pathTop;
int** result;
int resultTop;
int* length;

void backtracking(int target, int startIndex, int* candidates, int candidatesSize, int sum) {
    if (sum > target) {
        return;
    }
    if (sum == target) {
        int* tempPath = malloc(sizeof(int) * pathTop);
        for (int i = 0; i < pathTop; i++) {
            tempPath[i] = path[i];
        }
        result[resultTop] = tempPath;
        length[resultTop++] = pathTop;
        return;
    }

    for (int i = startIndex; i < candidatesSize; i++) {
        sum += candidates[i];
        path[pathTop++] = candidates[i];
        backtracking(target, i, candidates, candidatesSize, sum);
        sum -= candidates[i];
        pathTop--;
    }
}

int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes){
    path = malloc(sizeof(int) * 50);
    result = malloc(sizeof(int*) * 200);
    length = malloc(sizeof(int) * 200);
    pathTop = resultTop = 0;
    backtracking(target, 0, candidates, candidatesSize, 0);

    *returnSize = resultTop;
    *returnColumnSizes = malloc(sizeof(int) * resultTop);
    for (int i = 0; i < resultTop; i++) {
        (*returnColumnSizes)[i] = length[i];
    }
    return result;
}
// @lc code=end

