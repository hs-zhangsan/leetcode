/*
 * @lc app=leetcode.cn id=59 lang=c
 *
 * [59] 螺旋矩阵 II
 */

// @lc code=start
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generateMatrix(int n, int* returnSize, int** returnColumnSizes){
    int** result = malloc(sizeof(int*) * n);
    for (int i = 0; i < n; i++) {
        result[i] = malloc(sizeof(int) * n);
    }
    int startX = 0, startY = 0;
    int loop = n / 2;
    int offset = 1;
    int count = 1;

    if (n % 2) {
        result[loop][loop] = n * n;
    }

    while (loop) {
        int i = startX, j = startY;

        while (j < startY + n - offset) {
            result[i][j++] = count++;
        }
        while (i < startX + n - offset) {
            result[i++][j] = count++;
        }
        while (j > startY) {
            result[i][j--] = count++;
        }
        while (i > startX) {
            result[i--][j] = count++;
        }

        offset += 2;
        startX++;
        startY++;
        loop--;
    }

    *returnSize = n;
    *returnColumnSizes = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        (*returnColumnSizes)[i] = n;
    }
    return result;
}
// @lc code=end

