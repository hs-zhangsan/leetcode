char* reverseLeftWords(char* s, int n){
    int len = strlen(s), i = 0;;
    char *ans = malloc(sizeof(char) * (len + 1));
    while(i < len){
        *(ans++) = s[(n + i++) % len];
    }
    *ans= '\0';
    return ans - len;
}