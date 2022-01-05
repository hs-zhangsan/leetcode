/*
 * @lc app=leetcode.cn id=738 lang=c
 *
 * [738] 单调递增的数字
 */

// @lc code=start
void itoa(int num, char* str, int* strSize) {
    *strSize = 0;
    while (num > 0) {
        str[(*strSize)++] = num % 10 + '0';
        num /= 10;
    }
    for (int i = 0; i < (*strSize) / 2; i++) {
        int tmp = str[i];
        str[i] = str[(*strSize) - 1 - i];
        str[(*strSize - 1 - i)] = tmp;
    }
}

int monotoneIncreasingDigits(int n){
    int strNSize;
    char strN[11];
    itoa(n, strN, &strNSize);

    int flag = strNSize;
    for (int i = strNSize - 1; i > 0; i--) {
        if (strN[i - 1] > strN[i]) {
            flag = i;
            strN[i - 1]--;
        }
    }
    for (int i = flag; i < strNSize; i++) {
        strN[i] = '9';
    }
    
    return atoi(strN);
}
// @lc code=end

