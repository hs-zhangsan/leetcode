/*
 * @lc app=leetcode.cn id=198 lang=c
 *
 * [198] 打家劫舍
 */

// @lc code=start
/*
int rob(int* nums, int numsSize){
    if (numsSize == 1) {
        return *nums;
    }

    int dp[numsSize];
    dp[0] = nums[0];
    dp[1] = fmax(nums[0], nums[1]);
    for (int i = 2; i < numsSize; i++) {
        dp[i] = fmax(dp[i - 2] + nums[i], dp[i - 1]);
    }

    return fmax(dp[numsSize - 1], dp[numsSize - 2]);
}
*/

/*优化1
int rob(int* nums, int numsSize){
    if (numsSize == 1) {
        return *nums;
    }

    int dp[2];
    dp[0] = nums[0];
    dp[1] = fmax(nums[0], nums[1]);
    for (int i = 2; i < numsSize; i++) {
        int sum = fmax(dp[0] + nums[i], dp[1]);
        dp[0] = dp[1];
        dp[1] = sum;
    }

    return fmax(dp[0], dp[1]);
}
*/

//优化2
int rob(int* nums, int numsSize){
    if (numsSize == 1) {
        return *nums;
    }

    nums[1] = fmax(nums[0], nums[1]);
    for (int i = 2; i < numsSize; i++) {
        nums[i] = fmax(nums[i - 2] + nums[i], nums[i - 1]);
    }

    return fmax(nums[numsSize - 1], nums[numsSize - 2]);
}
// @lc code=end

