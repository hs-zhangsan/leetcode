//  **********   KMP 算法看不懂！！  **********

/*
    暴力匹配
    我们可以让字符串 needle 与字符串 haystack 的所有长度为 m 的子串均匹配一次。
    为了减少不必要的匹配，我们每次匹配失败即立刻停止当前子串的匹配，对下一个子串继续匹配。
    如果当前子串匹配成功，我们返回当前子串的开始位置即可。
    如果所有子串都匹配失败，则返回 -1。
*/

int strStr(char * haystack, char * needle){
    int m = strlen(haystack), n = strlen(needle);
    for (int i = 0; i + n <= m; i++) {
        bool flag = true;
        for (int j = 0; j < n; j++) {
            if (haystack[i + j] != needle[j]) {
                flag = false;
                break;
            }
        }
        if (flag) {
            return i;
        }
    }
    return -1;
}