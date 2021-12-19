/*
 * @lc app=leetcode.cn id=202 lang=c
 *
 * [202] 快乐数
 */

// @lc code=start
int getSquareSum(int num) {
    int ret = 0;
    while (num) {
        ret += (num % 10) * (num % 10);
        num /= 10;
    }
    return ret;
}

bool isHappy(int n){
    int num = getSquareSum(n);
    int* hash = calloc(sizeof(int), 820);

    while (num != 1) {
        if (hash[num] == 1) {
            return false;
        } else {
            hash[num]++;
        }
        num = getSquareSum(num);
    }

    return true;
}
// @lc code=end

