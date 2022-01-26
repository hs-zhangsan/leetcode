/*
 * @lc app=leetcode.cn id=216 lang=c
 *
 * [216] 组合总和 III
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

void backtracking(int targetSum, int k, int sum, int startIndex) {
    if (pathTop == k) {
        if (sum > targetSum) {
            return;
        }

        if (sum == targetSum) {
            int* tempPath = malloc(sizeof(int) * k);
            for (int i = 0; i < k; i++) {
                tempPath[i] = path[i];
            }
            result[resultTop++] = tempPath;
        }
        return;
    }

    for (int i = startIndex; i <= 9 - (k - pathTop) + 1; i++) {
        sum += i;
        path[pathTop++] = i;
        backtracking(targetSum, k, sum, i + 1);
        sum -= i;
        pathTop--;
    }
}

int** combinationSum3(int k, int n, int* returnSize, int** returnColumnSizes){
    path = malloc(sizeof(int) * k);
    result = malloc(sizeof(int*) * 20);
    pathTop = resultTop = 0;

    backtracking(n, k, 0, 1);

    *returnSize = resultTop;
    *returnColumnSizes = malloc(sizeof(int) * resultTop);
    for(int i = 0; i < resultTop; i++) {
        (*returnColumnSizes)[i] = k;
    }
    return result;
}
// @lc code=end

