/*
 * @lc app=leetcode.cn id=541 lang=c
 *
 * [541] 反转字符串 II
 */

// @lc code=start
char * reverseStr(char * s, int k){
    int len = strlen(s);

    for (int i = 0; i < len; i += (2 * k)) {
        //判断剩余字符是否少于 k
        k = i + k > len ? len - i : k;

        int left = i;
        int right = i + k - 1;
        while (left < right) {
            char temp = s[left];
            s[left++] = s[right];
            s[right--] = temp;
        }
    }

    return s;
}
// @lc code=end

