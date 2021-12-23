/*
 * @lc app=leetcode.cn id=1047 lang=c
 *
 * [1047] 删除字符串中的所有相邻重复项
 */

// @lc code=start


char * removeDuplicates(char * s){
    int n = strlen(s);
    char* stk = malloc(sizeof(char) * (n + 1));
    int retSize = 0;

    for (int i = 0; i < n; i++) {
        if (retSize > 0 && stk[retSize - 1] == s[i]) {
            retSize--;
        } else {
            stk[retSize++] = s[i];
        }
    }
    stk[retSize] = '\0';

    return stk;
}
// @lc code=end

