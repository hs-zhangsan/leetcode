/*
 * @lc app=leetcode.cn id=53 lang=c
 *
 * [53] 最大子数组和
 */

// @lc code=start


int maxSubArray(int* nums, int numsSize){
    int ret = INT_MIN;
    int sum = 0;

    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
        ret = fmax(ret, sum);
        
        if (sum < 0) {
            sum = 0;
        }
    }

    return ret;
}
// @lc code=end

