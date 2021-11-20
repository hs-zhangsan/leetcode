//  思路看代码。

char* replaceSpace(char* s){
    char* ch = malloc(sizeof(char) * strlen(s) * 3 + 1);
    int size = 0;

    while (*s) {
        if (*s == ' ') {
            ch[size++] = '%';
            ch[size++] = '2';
            ch[size++] = '0';
        }
        else {
            ch[size++] = *s;
        }
        s++;
    }
    ch[size] = 0;

    return ch;
}