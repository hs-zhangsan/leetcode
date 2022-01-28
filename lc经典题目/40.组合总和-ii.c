/*
 * @lc app=leetcode.cn id=40 lang=c
 *
 * [40] 组合总和 II
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
int* length;

int cmp(const void* a, const void* b) {
    return *((int*)a) - *((int*)b);
}

int backtracking(int* candidates, int candidatesSize, int target, int sum, int startIndex) {
    if (sum >= target) {
        if (sum == target) {
            int* tempPath = malloc(sizeof(int) * pathTop);
            for (int i = 0; i < pathTop; i++) {
                tempPath[i] = path[i];
            }
            result[resultTop] = tempPath;
            length[resultTop++] = pathTop;
            
        }
        return;
    }

    for (int i = startIndex; i < candidatesSize; i++) {
        if (i > startIndex && candidates[i] == candidates[i - 1]) {
            continue;
        }
        path[pathTop++] = candidates[i];
        sum += candidates[i];
        backtracking(candidates, candidatesSize, target, sum, i + 1);
        sum -= candidates[i];
        pathTop--;
    }
}

int** combinationSum2(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes){
    path = malloc(sizeof(int) * 50);
    result = malloc(sizeof(int*) * 100);
    length = malloc(sizeof(int) * 100);
    pathTop = resultTop = 0;
    qsort(candidates, candidatesSize, sizeof(int), cmp);

    backtracking(candidates, candidatesSize, target, 0, 0);

    *returnSize = resultTop;
    *returnColumnSizes = malloc(sizeof(int) * resultTop);
    for (int i = 0; i < resultTop; i++) {
        (*returnColumnSizes)[i] = length[i];
    }
    return result;
}
// @lc code=end

