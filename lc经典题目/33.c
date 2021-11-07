/*
    局部有序，依然可以用二分查找。
    取中间值，然后分为2个部分，必定有一边严格有序。
    分情况查找，除了严格有序的其他都是反例。
    具体思路看代码。
*/
int search(int* nums, int numsSize, int target){
    int left = 0, right = numsSize - 1, mid = numsSize;
    while (left <= right){
        mid = ((right - left) >> 1) + left;
        if (nums[mid] == target){
            return mid;
        }
        if (nums[left] <= nums[mid]){
            if (nums[left] <= target && target < nums[mid]){
                right  = mid - 1;
            } else{
                left = mid + 1;
            }
        } else{
            if (nums[mid] < target && target <= nums[right]){
                left = mid + 1;
            } else{
                right = mid - 1;
            }
        }
    }
    return -1;
}