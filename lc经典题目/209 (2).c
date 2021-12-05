// 双指针（滑动窗口）
// 注意边界条件

int minSubArrayLen(int target, int* nums, int numsSize){
    int left = 0, right = 0, sum = 0, ans= numsSize + 1;

    while (left < numsSize) {
        if ((right < numsSize) && sum < target) {
            sum += nums[right++];
        } else {
            sum -= nums[left++];
        }

        if (sum >= target) {
            ans = fmin(ans, right - left);
        }
    }

    return ans == numsSize + 1 ? 0 : ans;
}