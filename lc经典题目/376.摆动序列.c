/*
 * @lc app=leetcode.cn id=376 lang=c
 *
 * [376] 摆动序列
 */

// @lc code=start


int wiggleMaxLength(int* nums, int numsSize){
    if (numsSize < 2) {
        return numsSize;
    }
    int prewdiff = nums[1] - nums[0];
    int ret = prewdiff != 0 ? 2 : 1;
    for (int i = 2; i < numsSize; i++) {
        int diff = nums[i] - nums[i - 1];
        if ((diff > 0 && prewdiff <= 0) || (diff < 0 && prewdiff >= 0)) {
            ret++;
            prewdiff = diff;
        }
    }
    return ret;
}
// @lc code=end

