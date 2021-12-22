/*
    假设有两个栈，分别为 s1 和 s2，则有如下：
    
    入队：
        将新入队的元素压入栈 s1
    
    出队：
        1. 如果栈B不为空，将在 s2 栈顶的元素出队
        2. 如果栈B为空，且栈 s1 不为空，将栈A中所有的元素压入栈 s2，然后将在 s2 栈顶的元素出队
        3. 如果栈B为空，且栈 s1 也为空，出队函数直接返回 -1
*/


typedef struct {
    int* s1, * s2;
    int top1, top2;
} CQueue;


CQueue* cQueueCreate() {
    CQueue* obj = (CQueue*)malloc(sizeof(CQueue));
    obj->s1 = (int*)malloc(sizeof(int) * 10000);
    obj->s2 = (int*)malloc(sizeof(int) * 10000);
    obj->top1 = 0;
    obj->top2 = 0;
    return obj;
}

void cQueueAppendTail(CQueue* obj, int value) {
    obj->s1[(obj->top1)++] = value;
}

int cQueueDeleteHead(CQueue* obj) {
    if (obj->top2 == 0) {
        if (obj->top1 == 0) {
            return -1;
        }

        while (obj->top1 > 0) {
            obj->s2[(obj->top2)++] = obj->s1[--(obj->top1)];
        }
    }

    return obj->s2[--(obj->top2)];
}

void cQueueFree(CQueue* obj) {
    free(obj->s1);
    free(obj->s2);
    free(obj);
}

/**
 * Your CQueue struct will be instantiated and called as such:
 * CQueue* obj = cQueueCreate();
 * cQueueAppendTail(obj, value);

 * int param_2 = cQueueDeleteHead(obj);

 * cQueueFree(obj);
*/