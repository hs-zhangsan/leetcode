/*
 * @lc app=leetcode.cn id=406 lang=c
 *
 * [406] 根据身高重建队列
 */

// @lc code=start

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int Compare(const void *a, const void *b) {
    int *peopleA = *(int **)a;
    int *peopleB = *(int **)b;
    int hA = peopleA[0];
    int hB = peopleB[0];
    int kA = peopleA[1];
    int kB = peopleB[1];

    if (hA == hB) {
        return kA - kB;
    }

    return hB - hA;
}

int** reconstructQueue(int** people, int peopleSize, int* peopleColSize, int* returnSize, int** returnColumnSizes){
    if (people == NULL || peopleSize == 0 || peopleColSize == NULL) {
        *returnSize = 0;
        return NULL;
    }

    qsort(people, peopleSize, sizeof(int *), Compare);

    int **result = (int **)malloc(sizeof(int *) * peopleSize);
    *returnSize = peopleSize;
    
    for (int i = 0; i < peopleSize; i++) {
        int k = people[i][1];
        memmove(&result[k + 1], &result[k], (i - k) * sizeof(int*));
        result[k] = (int *)malloc(sizeof(int) * 2);
        result[k][0] = people[i][0];
        result[k][1] = people[i][1];
    }

    *returnColumnSizes = (int *)malloc(sizeof(int) * peopleSize);
    for (int i = 0; i < peopleSize; i++) {
        (*returnColumnSizes)[i] = 2;
    }

    return result;
}
// @lc code=end

