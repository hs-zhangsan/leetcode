/*
 * @lc app=leetcode.cn id=150 lang=c
 *
 * [150] 逆波兰表达式求值
 */

// @lc code=start
_Bool isnumber(char* str) {
    return strlen(str) > 1 || (str[0] >= '0' && str[0] <= '9');
}

int evalRPN(char ** tokens, int tokensSize){
    int* stack = malloc(sizeof(int) * tokensSize);
    int stackTop = 0;
    for (int i = 0; i < tokensSize; i++) {
        char* token = tokens[i];
        if (isnumber(token)) {
            stack[stackTop++] = atoi(tokens[i]);
        } else {
            int num1 = stack[--stackTop];
            int num2 = stack[--stackTop];
            switch (token[0]) {
                case '+' :
                stack[stackTop++] = num2 + num1;
                break;
                case '-' :
                stack[stackTop++] = num2 - num1;
                break;
                case '*' :
                stack[stackTop++] = num2 * num1;
                break;
                case '/' :
                stack[stackTop++] = num2 / num1;
                break;
            }
        }
    }
    return stack[stackTop - 1];
}
// @lc code=end

