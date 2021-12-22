/*
    ����������ջ���ֱ�Ϊ s1 �� s2���������£�
    
    ��ӣ�
        ������ӵ�Ԫ��ѹ��ջ s1
    
    ���ӣ�
        1. ���ջB��Ϊ�գ����� s2 ջ����Ԫ�س���
        2. ���ջBΪ�գ���ջ s1 ��Ϊ�գ���ջA�����е�Ԫ��ѹ��ջ s2��Ȼ���� s2 ջ����Ԫ�س���
        3. ���ջBΪ�գ���ջ s1 ҲΪ�գ����Ӻ���ֱ�ӷ��� -1
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