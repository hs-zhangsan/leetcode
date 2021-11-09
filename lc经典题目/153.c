/*
    有序用二分查找。
    若中间值大于最右侧值，则最小值一定在区间 [mid, right],
    若中间值小于最右侧值，则最小值一定在区间 [left, mid]。
    由于数组不包含重复元素，并且只要当前的区间长度不为 1，mid 就不会与 right 重合;
    而如果当前的区间长度为, 这说明我们已经可以结束二分查找了，因此不会存在 nums[mid] = nums[right] 的情况。
    当二分查找结束时，我们就得到了最小值所在的位置。
    注意边界的情况，循环条件为 left < right，而不是 left <= right。
*/

int findMin(int* nums, int numsSize){
    int left = 0, right = numsSize - 1, mid = numsSize;
    while (left < right){
        mid = ((right - left) >> 1) + left;
        if (nums[mid] > nums[right]){
            left = mid + 1;
        } else{
            right = mid;
        }
    }
    return nums[left];
}