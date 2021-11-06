/*
    直观的思路肯定是从前往后遍历一遍，用两个变量记录第一次和最后一次遇见target的下标。
    但这个方法的时间复杂度为O(n),没有利用到数组升序排列的条件。
    由于数组已经排序，因此整个数组是单调递增的，我们可以利用二分法来加速查找的过程。
    考虑 target 开始和结束位置，其实我们要找的就是数组中「第一个等于target 的位置」
    （记为 leftIdx）和「第一个大于target的位置减一」（记为 rightIdx）。
    二分查找中，寻找 leftIdx 即为在数组中寻找第一个大于等于 target 的下标，
    寻找rightIdx即为在数组中寻找第一个大于target 的下标，然后将下标减一。
    两者的判断条件不同，为了代码的复用，我们定义 binarySearch (nums, target, lower) 
    表示在 nums 数组中二分查找 target 的位置，如果 lower 为 true ，则查找第个大于等于 target的下标，
    否则查找第一个大于target 的下标。
    最后，因为target可能不存在数组中，因此我们需要重新校验我们得到的两个下标 leftIdx 和 rightIdx，
    看是否符合条件，如果符合条件就返回[leftIdx, rightIdx],不符合就返回[-1, -1]。
*/

int binarySearch(int* nums, int numsSize, int target, bool lower){
    int left = 0, right = numsSize - 1, ans = numsSize;

    while (left <= right){
        int mid = ((right - left) >> 1) + left;
        if (nums[mid] > target || (lower && nums[mid] >= target)){
            right = mid - 1;
            ans = mid;
        } else{
            left = mid + 1;
        }
    }

    return ans;
}

int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    int leftIdx = binarySearch(nums, numsSize, target, true);
    int rightIdx = binarySearch(nums, numsSize, target, false) - 1;
    int* ret = malloc(sizeof(int) * 2);
    *returnSize = 2;

    if (leftIdx <= rightIdx && rightIdx < numsSize && nums[leftIdx] == target && nums[rightIdx] == target){
        ret[0] = leftIdx, ret[1] = rightIdx;
        return ret;
    }
    ret[0] = -1, ret[1] = -1;
    return ret;
}