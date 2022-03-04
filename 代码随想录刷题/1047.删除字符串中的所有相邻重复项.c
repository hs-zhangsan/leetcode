/*
 * @lc app=leetcode.cn id=1047 lang=c
 *
 * [1047] 删除字符串中的所有相邻重复项
 */

// @lc code=start
char * removeDuplicates(char * s){
    int len = strlen(s);
    char* stack = malloc(sizeof(int) * len);
    int count = 0;
    for (int i = 0; i < len; i++) {
        if (count > 0 && s[i] == stack[count - 1]) {
            count--;
        } else {
            stack[count++] = s[i];
        }
    }
    stack[count] = '\0';
    return stack;
}
// @lc code=end

