/*
 * @lc app=leetcode.cn id=77 lang=c
 *
 * [77] 组合
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
int** ans;
int ansTop;

void backtracking(int n, int k, int startIndex) {
    if (pathTop == k) {
        int* temp = malloc(sizeof(int) * k);
        for (int i = 0; i < k; i++) {
            temp[i] = path[i];
        }
        ans[ansTop++] = temp;
        return ; 
    }

    //原判断条件为 j <= n，剪枝后为 j <= n - (k - pathTop) + 1
    for (int j = startIndex; j <= n - (k - pathTop) + 1; j++) {
        path[pathTop++] = j;
        backtracking(n, k, j + 1);
        pathTop--;
    }
}

int** combine(int n, int k, int* returnSize, int** returnColumnSizes){
    path = malloc(sizeof(int) * k);
    ans = malloc(sizeof(int*) * 10000);
    pathTop = ansTop = 0;

    backtracking(n, k, 1);

    *returnSize = ansTop;
    *returnColumnSizes = malloc(sizeof(int) * (*returnSize));
    for (int i = 0; i < *returnSize; i++) {
        (*returnColumnSizes)[i] = k;
    }
    return ans;
}
// @lc code=end

