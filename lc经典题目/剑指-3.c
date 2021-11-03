int findRepeatNumber(int* nums, int numsSize){
    int* arr = (int*)malloc(sizeof(int) * numsSize);

    for (int i = 0; i < numsSize; ++i){
        if (arr[nums[i]] != 1){
            arr[nums[i]] = 0;
        }
        ++arr[nums[i]];
        if (arr[nums[i]] > 1){
            return nums[i];
        }
    }

    return -1;
}