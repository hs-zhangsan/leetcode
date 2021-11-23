//  **********   KMP �㷨����������  **********

/*
    ����ƥ��
    ���ǿ������ַ��� needle ���ַ��� haystack �����г���Ϊ m ���Ӵ���ƥ��һ�Ρ�
    Ϊ�˼��ٲ���Ҫ��ƥ�䣬����ÿ��ƥ��ʧ�ܼ�����ֹͣ��ǰ�Ӵ���ƥ�䣬����һ���Ӵ�����ƥ�䡣
    �����ǰ�Ӵ�ƥ��ɹ������Ƿ��ص�ǰ�Ӵ��Ŀ�ʼλ�ü��ɡ�
    ��������Ӵ���ƥ��ʧ�ܣ��򷵻� -1��
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