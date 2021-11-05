/*
    二分查找
    假设题意是叫你在排序数组中寻找是否存在个目标值，
    那么训练有素的读者肯定立马就能想到利用二分法在O(log n)的时间内找到是否存在目标值。
    但这题还多了个额外的条件，即如果不存在数组中的时候需要返回按顺序插入的位置，那我们还能用二分法么？
    答案是可以的，我们只需要稍作修改即可。
    考虑这个插入的位置 pos ，它成立的条件为：nums[pos - 1] < target < nums[pos]
    其中nums代表排序数组。由于如果存在这个目标值，我们返回的索引也是pos，因此我们可以将两个
    条件合并得出最后的目标：「在一 个有序数组中找第一个大于等于target 的下标」。
    问题转化到这里，直接套用二分法即可，即不断用二分法逼近查找第个大于等于 target的下标。
    ans 初值设置为数组长度可以省略边界条件的判断，因为存在一种情况是 target 大于数组中的所有数，此时需要插入到数组长度的位置。
*/

int searchInsert(int* nums, int numsSize, int target){
    int left = 0, right = numsSize - 1, ans = numsSize;
    while (left <= right){
        int mid = ((right - left) >> 1) + left;
        if (target <= nums[mid]){
            ans = mid;
            right = mid - 1;
        } else{
            left = mid + 1;
        }
    }
    return ans;
}