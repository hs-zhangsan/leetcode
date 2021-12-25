/*
 * @lc app=leetcode.cn id=1021 lang=c
 *
 * [1021] 删除最外层的括号
 */

// @lc code=start
char * removeOuterParentheses(char * s){
    int count = 0, k = 0;
    char* ans = malloc(sizeof(char) * (strlen(s) + 1));
    //原地操作字符数组s时间超过15%，使用额外数组时间超过100%。

    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == '(') {
            if (count++ != 0) {
                ans[k++] = s[i];
            }
        }
        if (s[i] == ')') {
            if (--count != 0) {
                ans[k++] = s[i];
            }
        }
    }
    ans[k] = '\0';

    return ans;
}
// @lc code=end

