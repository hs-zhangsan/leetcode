char* replaceSpace(char* s){
    //ͳ�ƿո�����
    int count = 0;
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        if (s[i] == ' ') {
            count++;
        }
    }

    //Ϊ���������ռ�
    int newLen = len + count * 2;
    char* result = malloc(sizeof(char) * newLen + 1);
    //��������鲢�滻�ո�
    for (int i = len - 1, j = newLen - 1; i >= 0; i--, j--) {
        if (s[i] != ' ') {
            result[j] = s[i];
        } else {
            result[j--] = '0';
            result[j--] = '2';
            result[j] = '%';
        }
    }
    result[newLen] = '\0';

    return result;
}