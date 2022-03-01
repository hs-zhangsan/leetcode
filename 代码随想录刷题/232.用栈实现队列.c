/*
 * @lc app=leetcode.cn id=232 lang=c
 *
 * [232] 用栈实现队列
 */

// @lc code=start
// 使用两个数组（栈）和指针定义队列，两个指针分别指向对应的栈顶
typedef struct {
    int stackInTop, stackOutTop;
    int stackIn[100], stackOut[100];
} MyQueue;

// 开辟一个队列
MyQueue* myQueueCreate() {
    MyQueue* queue = malloc(sizeof(MyQueue));
    queue->stackInTop = 0;
    queue->stackOutTop = 0;
    return queue;
}

// 将元素存入输入栈中，存入后栈顶指针 +1
void myQueuePush(MyQueue* obj, int x) {
    obj->stackIn[(obj->stackInTop)++] = x;
}

int myQueuePop(MyQueue* obj) {
    // 优化：复制栈顶指针，减少对内存的访问次数
    int stackInTop = obj->stackInTop;
    int stackOutTop = obj->stackOutTop;

    // 若输出栈为空
    if (stackOutTop == 0) {
        // 将输入栈中所有元素复制到输出栈中
        while (stackInTop > 0) {
            obj->stackOut[stackOutTop++] = obj->stackIn[--stackInTop];
        }
    }
    // 将输出栈栈顶元素出栈并保存
    int top = obj->stackOut[--stackOutTop];
    // 将输出栈中元素放回输入栈中
    while (stackOutTop > 0) {
        obj->stackIn[stackInTop++] = obj->stackOut[--stackOutTop];
    }

    // 更新栈顶指针
    obj->stackInTop = stackInTop;
    obj->stackOutTop = stackOutTop;

    // 返回队列中的第一个元素
    return top;
}

// 返回输入栈的栈底元素
int myQueuePeek(MyQueue* obj) {
    return obj->stackIn[0];
}

// 若输入栈和输出栈都为空，则队列为空
bool myQueueEmpty(MyQueue* obj) {
    return obj->stackInTop == 0 && obj->stackOutTop == 0;
}

// 将栈顶指针都归 0
void myQueueFree(MyQueue* obj) {
    obj->stackInTop = 0;
    obj->stackOutTop = 0;
}
// @lc code=end

