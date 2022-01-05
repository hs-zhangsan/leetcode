/*
 * @lc app=leetcode.cn id=155 lang=c
 *
 * [155] 最小栈
 */

// @lc code=start
#define MAX_SIZE 10000

typedef struct {
    int data[MAX_SIZE];
    int top;
    int min;
} MinStack;

MinStack* minStackCreate() {
    MinStack *obj = malloc(sizeof(MinStack));
    if(obj){
        obj->top = -1;
        obj->min = INT_MAX;
        return obj;
    }
    return NULL;
}

void minStackPush(MinStack* obj, int x) {
    if(obj->top == MAX_SIZE - 1) {
        return;
    }
    
    obj->data[++obj->top] = x;
    obj->min = fmin(obj->min, x);
}

void minStackPop(MinStack* obj) {
    if(obj->top < 0) {
        obj->min = INT_MAX;
        return;
    }

    obj->top--;
    obj->min = INT_MAX;
    for(int i = 0; i <= obj->top; i++)
        obj->min = fmin(obj->min, obj->data[i]);
}

int minStackTop(MinStack* obj) {
    return obj->data[obj->top];
}

int minStackGetMin(MinStack* obj) {
    return obj->min;
}

void minStackFree(MinStack* obj) {
    free(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, val);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/
// @lc code=end

