/*
 * @lc app=leetcode.cn id=56 lang=c
 *
 * [56] 合并区间
 */

// @lc code=start


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int cmp(void* a, void* b) {
    int* aa = *(int**)a;
    int* bb = *(int**)b;
    return aa[0] - bb[0];
}

int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes){
    if (intervalsSize == 0) {
        return NULL;
    }
    qsort(intervals, intervalsSize, sizeof(intervals[0]), cmp);
    int** ret = malloc(sizeof(int*) * intervalsSize);
    int j = -1;
    for (int i = 0; i < intervalsSize; i++) {
        ret[i] = malloc(sizeof(int) * 2);
        if (j == -1 || ret[j][1] < intervals[i][0]) {
            ret[++j] = intervals[i];
        } else {
            ret[j][1] = fmax(ret[j][1], intervals[i][1]);
        }
    }
    *returnSize = j + 1;
    *returnColumnSizes = intervalsColSize;
    return ret;
}
// @lc code=end

