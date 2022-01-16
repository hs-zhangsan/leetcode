/*
 * @lc app=leetcode.cn id=509 lang=c
 *
 * [509] 斐波那契数
 */

// @lc code=start
int fib(int n){
    if (n < 2) {
        return n;
    }

    int p = 0, q = 0, r = 1;
    for (int i = 2; i <= n; i++) {
        p = q;
        q = r;
        r = p + q;
    }

    return r;
}
// @lc code=end

