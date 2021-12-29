/*
 * @lc app=leetcode.cn id=122 lang=c
 *
 * [122] 买卖股票的最佳时机 II
 */

// @lc code=start

/* 动态规划
int maxProfit(int* prices, int pricesSize){
    int dp0 = 0, dp1 = -prices[0];
    for (int i = 0; i < pricesSize; i++) {
        dp0 = fmax(dp0, dp1 + prices[i]);
        dp1 = fmax(dp1, dp0 - prices[i]);
    }
    return dp0;
}
*/

//贪心
int maxProfit(int* prices, int pricesSize) {
    int ans = 0;
    for (int i = 1; i < pricesSize; i++) {
        ans += fmax(0, prices[i] - prices[i - 1]);
    }
    return ans;
}
// @lc code=end

