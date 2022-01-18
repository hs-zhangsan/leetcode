/*
 * @lc app=leetcode.cn id=746 lang=c
 *
 * [746] 使用最小花费爬楼梯
 */

// @lc code=start
/*
int minCostClimbingStairs(int* cost, int costSize){
    int dp[costSize + 1];
    dp[0] = 0;
    dp[1] = 0;
    for (int i = 2; i < costSize + 1; i++) {
        dp[i] = fmin(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
    }
    return dp[costSize];
}
*/

//优化
int minCostClimbingStairs(int* cost, int costSize) {
    int dp[2] = {};
    int dpi;
    for (int i = 2; i < costSize + 1; i++) {
        dpi = fmin(dp[1] + cost[i - 1], dp[0] + cost[i - 2]);
        dp[0] = dp[1];
        dp[1] = dpi;
    }
    return dpi;
}
// @lc code=end

