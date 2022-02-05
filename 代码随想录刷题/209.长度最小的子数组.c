/*
 * @lc app=leetcode.cn id=209 lang=c
 *
 * [209] 长度最小的子数组
 */

// @lc code=start
int minSubArrayLen(int target, int* nums, int numsSize){
    int minLength = INT_MAX;
    int sum = 0;
    for (int start = 0, end = 0; end < numsSize; end++) {
        sum += nums[end];
        while (sum >= target) {
            minLength = fmin(minLength, end - start + 1);
            sum -= nums[start++];
        }
    }
    return minLength == INT_MAX ? 0 : minLength;
}
// @lc code=end

