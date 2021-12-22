/*
 * @lc app=leetcode.cn id=225 lang=c
 *
 * [225] 用队列实现栈
 */

// @lc code=start
#define LEN 20

typedef struct queue {
    int* data;
    int head, rear, size;
} Queue;

typedef struct {
    Queue* q1, * q2;
} MyStack;

Queue* initQueue(int n) {
    Queue* obj = malloc(sizeof(Queue));
    obj->data = malloc(sizeof(int) * n);
    obj->head = -1;
    obj->rear = -1;
    obj->size = n;
    return obj;
}

void enQueue(Queue* obj, int n) {
    if (obj->head == -1) {
        obj->head = 0;
    }
    obj->rear = (obj->rear + 1) % obj->size;
    obj->data[obj->rear] = n;
}

int deQueue(Queue* obj) {
    int a = obj->data[obj->head];
    if (obj->head == obj->rear) {
        obj->rear = -1;
        obj->head = -1;
        return a;
    }
    obj->head = (obj->head + 1) % obj->size;
    return a;
}

int isEmpty(Queue* obj) {
    return obj->head == -1;
}

MyStack* myStackCreate() {
    MyStack* obj = malloc(sizeof(MyStack));
    obj->q1 = initQueue(LEN);
    obj->q2 = initQueue(LEN);
    return obj;
}

void myStackPush(MyStack* obj, int x) {
    if (isEmpty(obj->q1)) {
        enQueue(obj->q2, x);
    } else {
        enQueue(obj->q1, x);
    }
}

int myStackPop(MyStack* obj) {
    if (isEmpty(obj->q1)) {
        while (obj->q2->head != obj->q2->rear) {
            enQueue(obj->q1, deQueue(obj->q2));
        }
        return deQueue(obj->q2);
    }
    while (obj->q1->head != obj->q1->rear) {
        enQueue(obj->q2, deQueue(obj->q1));
    }
    return deQueue(obj->q1);
}

int myStackTop(MyStack* obj) {
    if (isEmpty(obj->q1)) {
        return obj->q2->data[obj->q2->rear];
    }
    return obj->q1->data[obj->q1->rear];
}

bool myStackEmpty(MyStack* obj) {
    if (obj->q1->head == -1 && obj->q2->head == -1) {
        return true;
    }
    return false;
}

void myStackFree(MyStack* obj) {
    free(obj->q1->data);
    obj->q1->data = NULL;
    free(obj->q1);
    obj->q1 = NULL;
    free(obj->q2->data);
    obj->q2->data = NULL;
    free(obj->q2);
    obj->q2 = NULL;
    free(obj);
    obj = NULL;
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);
 
 * int param_2 = myStackPop(obj);
 
 * int param_3 = myStackTop(obj);
 
 * bool param_4 = myStackEmpty(obj);
 
 * myStackFree(obj);
*/
// @lc code=end

