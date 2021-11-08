/*
    本篇题解基于 leetcode33。
    对于数组中有重复元素的情况，二分查找时可能会有 a[left] = a[mid] = a[right],
    此时无法判断区间 [left, mid] 和区间 [mid + 1, right] 哪个是有序的。
    例如 nums = [3, 1, 2, 3, 3, 3, 3]，target = 2，首次二分时无法判断区间 [0, 3] 和区间 [4, 6] 哪个是有序的。
    对于这种情况，我们只能将当前二分区间的左边界加一，右边界减一，然后在新区间上继续二分查找。
*/

bool search(int* nums, int numsSize, int target){
    if (numsSize == 0){
        return false;
    }
    if (numsSize == 1){
        return nums[0] == target;
    }

    int left = 0, right = numsSize - 1;
    while (left <= right){
        int mid = ((right - left) >> 1) + left;
        if (nums[mid] == target){
            return true;
        }
        if (nums[left] == nums[mid] && nums[mid] == nums[right]){
            ++left;
            --right;
        } else if (nums[left] <= nums[mid]){
            if (nums[left] <= target && target < nums[mid]){
                right = mid - 1;
            } else{
                left = mid + 1;
            }
        } else {
            if (nums[right] >= target && target > nums[mid]){
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }
    return false;
}