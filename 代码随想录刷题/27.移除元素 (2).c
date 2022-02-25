int removeElement(int* nums, int numsSize, int val){
    int fast = 0, slow = 0;
    while (fast < numsSize) {
        if (nums[fast] != val) {
            nums[slow++] = nums[fast];
        }
        fast++;
    }
    return slow;
}