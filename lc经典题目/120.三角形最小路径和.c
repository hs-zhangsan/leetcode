/*
 * @lc app=leetcode.cn id=120 lang=c
 *
 * [120] 三角形最小路径和
 */

// @lc code=start
/*
int minimumTotal(int** triangle, int triangleSize, int* triangleColSize){
    int dp[triangleSize][triangleSize];
    dp[0][0] = triangle[0][0];
    for (int i = 1; i < triangleSize; i++) {
        dp[i][0] = dp[i - 1][0] + triangle[i][0];

        for (int j = 1; j < i; j++) {
            dp[i][j] = fmin(dp[i - 1][j], dp[i - 1][j - 1]) + triangle[i][j];
        }

        dp[i][i] = dp[i - 1][i - 1] + triangle[i][i];
    }

    int result = dp[triangleSize - 1][0];
    for (int i = 1; i < triangleSize; i++) {
        result = fmin(result, dp[triangleSize - 1][i]);
    }

    return result;
}
*/

//优化
int minimumTotal(int** triangle, int triangleSize, int* triangleColSize){
    for (int i = 1; i < triangleSize; i++) {
        triangle[i][0] = triangle[i - 1][0] + triangle[i][0];

        for (int j = 1; j < i; j++) {
            triangle[i][j] = fmin(triangle[i - 1][j], triangle[i - 1][j - 1]) + triangle[i][j];
        }

        triangle[i][i] = triangle[i - 1][i - 1] + triangle[i][i];
    }

    for (int i = 1; i < triangleSize; i++) {
        triangle[triangleSize - 1][0] = fmin(triangle[triangleSize - 1][0], triangle[triangleSize - 1][i]);
    }

    return triangle[triangleSize - 1][0];
}
// @lc code=end

