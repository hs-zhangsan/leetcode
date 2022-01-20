/*
 * @lc app=leetcode.cn id=64 lang=c
 *
 * [64] 最小路径和
 */

// @lc code=start
/*
int minPathSum(int** grid, int gridSize, int* gridColSize){
    int dp[gridSize][*gridColSize];
    dp[0][0] = grid[0][0];
    for (int i = 1; i < gridSize; i++) {
        dp[i][0] = grid[i][0] + dp[i - 1][0];
    }
    for (int j = 1; j < *gridColSize; j++) {
        dp[0][j] = grid[0][j] + dp[0][j - 1];
    }
    for (int i = 1; i < gridSize; i++) {
        for (int j = 1; j < *gridColSize; j++) {
            dp[i][j] = grid[i][j] + fmin(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[gridSize - 1][*gridColSize - 1];
}
*/

//优化
int minPathSum(int** grid, int gridSize, int* gridColSize){
    for (int i = 1; i < gridSize; i++) {
        grid[i][0] = grid[i][0] + grid[i - 1][0];
    }
    for (int j = 1; j < *gridColSize; j++) {
        grid[0][j] = grid[0][j] + grid[0][j - 1];
    }
    for (int i = 1; i < gridSize; i++) {
        for (int j = 1; j < *gridColSize; j++) {
            grid[i][j] = grid[i][j] + fmin(grid[i - 1][j], grid[i][j - 1]);
        }
    }
    return grid[gridSize - 1][*gridColSize - 1];
}
// @lc code=end

