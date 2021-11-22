/*
    ͨ������£�����������С�������ڴ�����ֵ��ұߡ�
    ��������ַ���������������ô���Խ�ÿ���ַ�����һ��������ֵ���ۼ�ÿ���ַ���Ӧ����ֵ���ɡ�
    ���� XXVII ������ X+X+V+I+I=10+10+5+1+1=27��
    ������С�������ڴ�����ֵ���ߵ���������ݹ�����Ҫ��ȥС�����֡�
    �����������������Ҳ���Խ�ÿ���ַ�����һ��������ֵ����һ�������Ҳ�����ֱ������򽫸����ֵķ���ȡ����
    ���� XIV ������ X?I+V=10?1+5=14��
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