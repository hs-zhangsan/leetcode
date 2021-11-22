/*
    通常情况下，罗马数字中小的数字在大的数字的右边。
    若输入的字符串满足该情况，那么可以将每个字符视作一个单独的值，累加每个字符对应的数值即可。
    例如 XXVII 可视作 X+X+V+I+I=10+10+5+1+1=27。
    若存在小的数字在大的数字的左边的情况，根据规则需要减去小的数字。
    对于这种情况，我们也可以将每个字符视作一个单独的值，若一个数字右侧的数字比它大，则将该数字的符号取反。
    例如 XIV 可视作 X?I+V=10?1+5=14。
*/

int romanToInt(char * s){
    int symbolValue[26];
    symbolValue['I' - 'A'] = 1;
    symbolValue['V' - 'A'] = 5;
    symbolValue['X' - 'A'] = 10;
    symbolValue['L' - 'A'] = 50;
    symbolValue['C' - 'A'] = 100;
    symbolValue['D' - 'A'] = 500;
    symbolValue['M' - 'A'] = 1000;
    int ans = 0;
    int n = strlen(s);
    for (int i = 0; i < n; i++) {
        int value = symbolValue[s[i] - 'A'];
        if (i < n - 1 && value < symbolValue[s[i + 1] - 'A']) {
            ans -= value;
        }
        else {
            ans += value;
        }
    }
    return ans;
}