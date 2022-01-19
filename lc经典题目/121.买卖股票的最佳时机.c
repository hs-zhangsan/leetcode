/*
 * @lc app=leetcode.cn id=121 lang=c
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
/*
int maxProfit(int* prices, int pricesSize){
    if (pricesSize == 0) {
        return 0;
    }

    int dp[pricesSize][2];
    dp[0][0] = -prices[0];
    dp[0][1] = 0;
    for (int i = 1; i < pricesSize; i++) {
        dp[i][0] = fmax(dp[i - 1][0], -prices[i]);
        dp[i][1] = fmax(dp[i - 1][1], dp[i - 1][0] + prices[i]);
    }

    return dp[pricesSize - 1][1];
}
*/

//优化
int maxProfit(int* prices, int pricesSize){
    if (pricesSize == 0) {
        return 0;
    }

    int dp[2][2];
    dp[0][0] = -prices[0];
    dp[0][1] = 0;
    for (int i = 1; i < pricesSize; i++) {
        //下面这两行写的真好，可惜不是我自己想出来的。
        dp[i % 2][0] = fmax(dp[(i - 1) % 2][0], -prices[i]);
        dp[i % 2][1] = fmax(dp[(i - 1) % 2][1], dp[(i - 1) % 2][0] + prices[i]); 
    }

    return dp[(pricesSize - 1) % 2][1];
}
// @lc code=end

