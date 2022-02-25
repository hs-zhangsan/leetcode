char* replaceSpace(char* s){
    int len = strlen(s);
    int count = 0;
    for (int i = 0; i < len; i++) {
        if (s[i] == ' ') {
            count++;
        }
    }

    int newLen = len + 2 * count;
    char* result = malloc(sizeof(char) * newLen + 1);
    for (int i = 0, j = 0; i < len; i++, j++) {
        if (s[i] == ' ') {
            result[j] = '%';
            result[j + 1] = '2';
            result[j + 2] = '0';
            j += 2;
        } else {
            result[j] = s[i];
        }
    }
    result[newLen] = '\0';

    return result;
}