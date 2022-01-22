/*
 * @lc app=leetcode.cn id=213 lang=c
 *
 * [213] 打家劫舍 II
 */

// @lc code=start
int rob(int* nums, int numsSize){
    if (numsSize == 1) {
        return *nums;
    }
    if (numsSize == 2) {
        return fmax(nums[0], nums[1]);
    }

    //分【包含首元素不包含尾元素】和【包含尾元素不包含首元素】两种情况进行考虑。
    //dp1 表示【包含首元素不包含尾元素】的情况；
    //dp2 表示【包含尾元素不包含首元素】的情况。
    int dp1[2], dp2[2];
    dp1[0] = nums[0], dp1[1] = fmax(nums[0], nums[1]);
    dp2[0] = nums[1], dp2[1] = fmax(nums[1], nums[2]);
    for (int i = 2; i < numsSize - 1; i++) {
        int sum1 = fmax(dp1[0] + nums[i], dp1[1]);
        int sum2 = fmax(dp2[0] + nums[i + 1], dp2[1]);
        dp1[0] = dp1[1], dp1[1] = sum1;
        dp2[0] = dp2[1], dp2[1] = sum2;
    }
    int ans1 = fmax(dp1[0], dp1[1]);
    int ans2 = fmax(dp2[0], dp2[1]);

    return fmax(ans1, ans2);
}
// @lc code=end

