/*
 * @lc app=leetcode.cn id=225 lang=c
 *
 * [225] 用队列实现栈
 */

// @lc code=start
/*
使用两个队列实现栈
typedef struct {
    int queue1[100], queue2[100];
    int front1, front2;
    int rear1, rear2;
} MyStack;


MyStack* myStackCreate() {
    MyStack* stack = malloc(sizeof(MyStack));
    stack->front1 = 0, stack->front2 = 0;
    stack->rear1 = 0, stack->rear2 = 0;
    return stack;
}

void myStackPush(MyStack* obj, int x) {
    obj->queue1[(obj->rear1)++] = x;
}

int myStackPop(MyStack* obj) {
    int front1 = obj->front1, front2 = obj->front2;
    int rear1 = obj->rear1, rear2 = obj->rear2;

    while (rear1 - front1 > 1) {
        obj->queue2[rear2++] = obj->queue1[front1++];
    }
    int top = obj->queue1[front1++];
    while (front2 != rear2) {
        obj->queue1[rear1++] = obj->queue2[front2++];
    }

    obj->front1 = front1, obj->front2 = front2;
    obj->rear1 = rear1, obj->rear2 = rear2;

    return top;
}

int myStackTop(MyStack* obj) {
    return obj->queue1[(obj->rear1) - 1];
}

bool myStackEmpty(MyStack* obj) {
    return obj->rear1 == obj->front1;
}

void myStackFree(MyStack* obj) {
    obj->front1 = 0, obj->front2 = 0;
    obj->rear1 = 0, obj->rear2 = 0;
}
 */

typedef struct {
    int queue[100];
    int front;
    int rear;
} MyStack;


MyStack* myStackCreate() {
    MyStack* stack = malloc(sizeof(MyStack));
    stack->front = 0;
    stack->rear = 0;
    return stack;
}

void myStackPush(MyStack* obj, int x) {
    obj->queue[(obj->rear)++] = x;
}

int myStackPop(MyStack* obj) {
    int front = obj->front;
    int rear = obj->rear;

    int size = rear - front;
    while (size-- > 1) {
        obj->queue[rear++] = obj->queue[front++];
    }
    int top = obj->queue[front++];

    obj->front = front;
    obj->rear = rear;

    return top;
}

int myStackTop(MyStack* obj) {
    return obj->queue[(obj->rear) - 1];
}

bool myStackEmpty(MyStack* obj) {
    return obj->rear == obj->front;
}

void myStackFree(MyStack* obj) {
    obj->front = 0;
    obj->rear = 0;
}
// @lc code=end

