/*
 * @lc app=leetcode.cn id=169 lang=c
 *
 * [169] 多数元素
 */

// @lc code=start


int majorityElement(int* nums, int numsSize){
    int candidate = -1;
    int count = 0;
    for (int i = 0; i < numsSize; i++) {
        if (count == 0) {
            candidate = nums[i];
        }
        if (nums[i] == candidate) {
            count++;
        } else {
            count--;
        }
    }
    return candidate;
}
// @lc code=end

