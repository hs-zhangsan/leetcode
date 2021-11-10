/*
    若将矩阵每一行拼接在上一行的末尾，则会得到一个升序数组，我们可以在该数组上二分找到目标元素。
    代码实现时，可以二分升序数组的下标，将其映射到原矩阵的行和列上。
    注意：若二维数组中的一维数组的元素个数不一，此方法会失效。
    还可以用两次二分查找，
    对矩阵的第一列的元素二分查找，找到最后一个不大于目标值的元素，然后在该元素所在行中二分查找目标值是否存在。
    即使二维数组中的一维数组的元素个数不一，此方法仍然可以正确处理。
*/

bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target){
    int left = 0, right = matrixSize * *matrixColSize - 1;
    int mid, ret;
    while (left <= right){
        mid = ((right - left) >> 1) + left;
        ret = matrix[mid / *matrixColSize][mid % *matrixColSize];
        if (ret == target){
            return true;
        } else if (ret > target){
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return false;
}