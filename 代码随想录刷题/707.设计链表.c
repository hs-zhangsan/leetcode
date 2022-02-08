/*
 * @lc app=leetcode.cn id=707 lang=c
 *
 * [707] 设计链表
 */

// @lc code=start
typedef struct MyLinkedListTag{
    int val;
    struct MyLinkedListTag* next;
} MyLinkedList;


MyLinkedList* myLinkedListCreate() {
    MyLinkedList* head = malloc(sizeof(MyLinkedList));
    head->next = NULL;
    return head;
}

int myLinkedListGet(MyLinkedList* obj, int index) {
    MyLinkedList* curr = obj->next;
    for (int i = 0; curr; i++) {
        if (i == index) {
            return curr->val;
        } else {
            curr = curr->next;
        }
    }
    return -1;
}

void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    MyLinkedList* newHead = malloc(sizeof(MyLinkedList));
    newHead->val = val;
    newHead->next = obj->next;
    obj->next = newHead;
}

void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    MyLinkedList* curr = obj;
    while (curr->next) {
        curr = curr->next;
    }
    MyLinkedList* newTail = malloc(sizeof(MyLinkedList));
    newTail->val = val;
    newTail->next = NULL;
    curr->next = newTail;
}

void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    //若 index <= 0，则在头部插入结点
    if (index <= 0) {
        myLinkedListAddAtHead(obj, val);
        return;
    }
    //若 0 < index <= 链表长度，则在第 index 个结点前插入结点
    //注意当 index = 链表长度时，实际就是在链表末尾插入结点
    MyLinkedList* curr = obj->next;
    for (int i = 1; curr; i++) {
        if (i == index) {
            MyLinkedList* newNode = malloc(sizeof(MyLinkedList));
            newNode->val = val;
            newNode->next = curr->next;
            curr->next = newNode;
            return;
        } else {
            curr = curr->next;
        }
    }
    //若 index > 链表长度，无需操作
}

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    if (index == 0) {
        MyLinkedList* temp = obj->next;
        if (temp) {
            obj->next = temp->next;
            free(temp);
        }
        return;
    }
    MyLinkedList* curr = obj->next;
    for (int i = 1; curr && curr->next; i++) {
        if (i == index) {
            MyLinkedList* temp = curr->next;
            curr->next = temp->next;
            free(temp);
            return;
        } else {
            curr = curr->next;
        }
    }
}

void myLinkedListFree(MyLinkedList* obj) {
    while (obj) {
        MyLinkedList* temp = obj;
        obj = obj->next;
        free(temp);
    }
}

/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);
 
 * myLinkedListAddAtHead(obj, val);
 
 * myLinkedListAddAtTail(obj, val);
 
 * myLinkedListAddAtIndex(obj, index, val);
 
 * myLinkedListDeleteAtIndex(obj, index);
 
 * myLinkedListFree(obj);
*/
// @lc code=end

