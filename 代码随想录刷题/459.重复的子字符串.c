/*
 * @lc app=leetcode.cn id=459 lang=c
 *
 * [459] 重复的子字符串
 */

// @lc code=start
//前缀表不减一版本
void getNext(int* next, char* s) {
    int j = 0;
    next[0] = j;
    for (int i = 1; i < strlen(s); i++) {
        while (j > 0 && s[i] != s[j]) {
            j = next[j - 1];
        }
        if (s[i] == s[j]) {
            j++;
        }
        next[i] = j;
    }
}

bool repeatedSubstringPattern(char * s){
    int len = strlen(s);
    int* next = malloc(sizeof(int) * len);
    getNext(next, s);
    if (next[len - 1] != 0 && len % (len - next[len - 1]) == 0) {
        return true;
    }
    return false;
}
// @lc code=end

