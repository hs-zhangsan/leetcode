/*
 * @lc app=leetcode.cn id=51 lang=c
 *
 * [51] N 皇后
 */

// @lc code=start
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
char** path;
char*** result;
int pathTop, resultTop;

int isValid(int a, int b, int n) {
    int i, j;

    for(i = 0; i < n; ++i) {
        if(path[b][i] == 'Q' || path[i][a] == 'Q') {
            return 0;
        }
    }

    i = b - 1;
    j = a - 1;
    while(i >= 0 && j >= 0) {
        if(path[i][j] == 'Q') {
            return 0;
        }
        i--, j--;
    }
    i = b + 1;
    j = a + 1;
    while(i < n && j < n) {
        if(path[i][j] == 'Q') {
            return 0;
        }
        i++, j++;
    }


    i = b - 1;
    j = a + 1;
    while(i >= 0 && j < n) {
        if(path[i][j] == 'Q') {
            return 0;
        }
        i--, j++;
    }
    i = b + 1;
    j = a - 1;
    while(j >= 0 && i < n) {
        if(path[i][j] == 'Q') {
            return 0;
        }
        i++, j--;
    }

    return 1;
}

void backtracking(int n, int depth) {
    if(pathTop == n) {
        char **tempPath = malloc(sizeof(char*) * pathTop);
        int i, j;
        for(i = 0; i < n; ++i) {
            tempPath[i] = malloc(sizeof(char) * n + 1);
            for(j = 0; j < n; ++j) {
                tempPath[i][j] = path[i][j];
            }
            tempPath[i][j] = '\0';
        }
        result[resultTop++] = tempPath;
        return;
    }

    for(int i = 0; i < n; ++i) {
        if(isValid(i, depth, n)) {
            path[depth][i] = 'Q';
            pathTop++;
            backtracking(n, depth + 1);
            path[depth][i] = '.';
            pathTop--;
        }
    }
}

char *** solveNQueens(int n, int* returnSize, int** returnColumnSizes){
    path = malloc(sizeof(char*) * n);
    result = malloc(sizeof(char**) * 400);
    pathTop = resultTop = 0;
    int i, j;
    for(i = 0; i < n; i++) {
        path[i] = malloc(sizeof(char) * n + 1);
        for(j = 0; j < n; j++) {
            path[i][j] = '.';
        }
        path[i][j] = '\0';
    }

    backtracking(n, 0);

    *returnSize = resultTop;
    *returnColumnSizes = malloc(sizeof(int) * resultTop);
    for(int i = 0; i < resultTop; i++) {
        (*returnColumnSizes)[i] = n;
    }
    return result;
}
// @lc code=end

