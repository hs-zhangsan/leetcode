/*
    本题考察对位运算的灵活使用，即使用位运算实现加法。
    设两数字的二进制形式 a, b，其求和 s = a + b，a(i) 代表 a 的二进制第 i 位，则分为以下四种情况：
        a(i)    b(i)    无进位和n(i)    进位c(i+1)
        0       0           0               0
        0       1           1               0
        1   	0           1               0
        1       1           0               1
    观察发现，无进位和 与 异或运算 规律相同，进位 和 与运算 规律相同（并需左移一位）。
    因此，无进位和 n 与进位 c 的计算公式如下：
        n=a⊕b      非进位和：异或运算
        c=a&b<<1    进位：与运算 + 左移一位
    （和s）=（非进位和n）+（进位c）。即可将 s = a + b 转化为：
        s = a + b ? s = n + c
    循环求 n 和 c ，直至进位 c = 0；此时 s = n，返回 n 即可。
    
    Q：若数字 a 和 b 中有负数，则变成了减法，如何处理？
    A：在计算机系统中，数值一律用 补码 来表示和存储。补码的优势：加法、减法可以统一处理（CPU只有加法器）。
    因此，以上方法 同时适用于正数和负数的加法 。
*/

int add(int a, int b) {
    /* a和b第一次计算完进位和、进位之后，将b 赋值为进位
     * 再与a进行第二次计算，直到进位为0，表示从低位到高位全部计算完
     * 所以这里需要循环处理所有的进位
     */
    while (b != 0){
        int temp = (unsigned int)(a & b) << 1;
        a = a^b;    /* a为无进位和 */
        b = temp;   /* b为进位 */
    }
    return a;
}