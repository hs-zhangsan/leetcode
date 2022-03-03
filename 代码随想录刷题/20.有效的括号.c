/*
 * @lc app=leetcode.cn id=20 lang=c
 *
 * [20] 有效的括号
 */

// @lc code=start
bool isValid(char * s) {
    int len = strlen(s);
    int* stack = malloc(sizeof(int) * len);
    int count = 0;
    for (int i = 0; i < len; i++) {
        if (s[i] == '(') {
            stack[count++] = ')';
        } else if (s[i] == '{') {
            stack[count++] = '}';
        } else if (s[i] == '[') {
            stack[count++] = ']';
        } else if (count == 0 || stack[count - 1] != s[i]) {
            // ⬆情况 2 和情况 3
            return  false;
        } else {
            count--;
        }
    }
    // 情况 1
    return count == 0;
}
// @lc code=end

