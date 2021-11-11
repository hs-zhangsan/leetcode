/*
    二分法比遍历还慢，没必要强行二分。
    具体思路看代码。
*/

//二分查找
int missingNumber(int* nums, int numsSize){
    int left = 0, right = numsSize - 1, mid = numsSize;
    while (left <= right) {
        mid = ((right - left) >> 2) + left;
        if (nums[mid] == mid) {
            left = mid + 1;
        } else {         //nums[mid] >= mid 恒成立。
            right = mid - 1;
        }
    }
    return left;
}

//遍历
int missingNumber(int* nums, int numsSize)
{
    int i = 0;
    while ( i < numsSize )
    {
        if(nums[i] == i)
            i++;
        else
                break;
    }
    return i;
}