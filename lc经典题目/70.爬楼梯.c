/*
 * @lc app=leetcode.cn id=70 lang=c
 *
 * [70] 爬楼梯
 */

// @lc code=start
/*版本一
int climbStairs(int n){
    if (n < 3) {
        return n;
    }

    int dp[n+1];
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i < n + 1; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}
*/

//优化
int climbStairs(int n) {
    if (n < 3) {
        return n;
    }

    int dp[3];
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i < n + 1; i++) {
        int sum = dp[1] + dp[2];
        dp[1] = dp[2];
        dp[2] = sum;
    }

    return dp[2];
}
// @lc code=end

