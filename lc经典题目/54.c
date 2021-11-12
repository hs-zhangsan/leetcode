/*
    可以将矩阵看成若干层，首先输出最外层的元素，其次输出次外层的元素，直到输出最内层的元素。
    定义矩阵的第 k 层是到最近边界距离为 k 的所有顶点。
    例如，下图矩阵最外层元素都是第 1 层，次外层元素都是第 2 层，剩下的元素都是第 3 层。
    [[1, 1, 1, 1, 1, 1, 1],
     [1, 2, 2, 2, 2, 2, 1],
     [1, 2, 3, 3, 3, 2, 1],
     [1, 2, 2, 2, 2, 2, 1],
     [1, 1, 1, 1, 1, 1, 1]]
    对于每层，从左上方开始以顺时针的顺序遍历所有元素。
    假设当前层的左上角位于 (top, left)，右下角位于 (bottom, right)，按照如下顺序遍历当前层的元素：
     1. 从左到右遍历上侧元素，依次为 (top, left) 到 (top, right)。
     2. 从上到下遍历右侧元素，依次为 (top+1, right) 到 (bottom, right)。
     3. 如果 left < right 且 top < bottom，则从右到左遍历下侧元素，
        依次为 (bottom, left) 到 (top+1, left)。
    遍历完当前层的元素之后，将 left 和 top 分别增加 1，将 right 和 bottom 分别减少 1，
    进入下一层继续遍历，直到遍历完所有元素为止。
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize){
    if (matrixSize == 0 || matrixColSize[0] == 0) {
        *returnSize = 0;
        return NULL;
    }

    int rows = matrixSize, columns = matrixColSize[0];
    int total = rows * columns;
    int* order = (int*)malloc(sizeof(int) * total);
    *returnSize = 0;

    int left = 0, right = columns - 1, top = 0, bottom = rows - 1;
    int row, column;
    while (left <= right && top <= bottom) {
        for (column = left; column <= right; column++) {
            order[(*returnSize)++] = matrix[top][column];
        }
        for (row = top + 1; row <= bottom; row++) {
            order[(*returnSize)++] = matrix[row][right];
        }
        if (left < right && top < bottom) {
            for (column = right - 1; column > left; column--) {
                order[(*returnSize)++] = matrix[bottom][column];
            }
            for (row = bottom; row > top; row--) {
                order[(*returnSize)++] = matrix[row][left];
            }
        }
        left++;
        right--;
        top++;
        bottom--;
    }
    return order;
}