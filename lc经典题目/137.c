/*
    数字电路。
    数组元素二进制位之和对3求模所得结果为只出现一次的元素的二进制位。
    我们只需要完成一个同一位上的三个1清零的过程，也就是a ? a ? a = 0，问题则迎刃冰解。
    （大概就是这个意思，具体操作看不太懂）
*/

int singleNumber(int *nums, int numsSize) {
    int a = 0, b = 0;
    for (int i = 0; i < numsSize; i++) {
        b = ~a & (b ^ nums[i]);
        a = ~b & (a ^ nums[i]);
    }
    return b;
}