/*
 * @lc app=leetcode.cn id=5 lang=c
 *
 * [5] 最长回文子串
 */

// @lc code=start
char * longestPalindrome(char * s){
    int n = strlen(s);
    if (n == 1) {
        return s;
    }

    int start = 0, end = n - 1;
    int maxLength = 0;
    bool dp[n][n];
    for (int i = n - 1; i >= 0; i--) {
        for (int j = i; j < n; j++) {
            if (s[i] != s[j]) {    //若 s[i] = s[j]
                dp[i][j] = false;
            } else {               //若 s[i] = s[j]
                if (j - i <= 1) {  //情况一和情况二
                    dp[i][j] = true;
                } else {           //情况三
                    dp[i][j] = dp[i + 1][j - 1];
                }
            }

            if (dp[i][j] && j - i + 1 >= maxLength) {
                maxLength = j - i + 1;
                start = i;
                end = j;
            }
        }
    }

    s[end + 1] = '\0';
    return s + start;
}
// @lc code=end

