#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

// 存储结构
typedef int ElemType;

typedef struct SeqStack {
    ElemType* _arr;
    int _top;
    int capacity;
} SeqStack;

// 初始化，构建一个空的顺序栈
void StackInint(SeqStack* stack);

// 清空 -> 如果栈存在则清空
void StackClear(SeqStack* stack);

// 销毁 -> 如果栈存在则销毁
void StackDestroy(SeqStack* stack);

// 返回1则栈空，返回0则栈非空
int StackEmpty(SeqStack* stack);

// 获取栈长度
int StackLength(SeqStack* stack);

// 获取栈顶元素
ElemType StackGetTop(SeqStack* stack);

// 入栈
void StackPush(SeqStack* stack, ElemType data);

// 出栈
void StackPop(SeqStack* stack);

// 初始化 -> 构建一个空的顺序栈
void StackInint(SeqStack* stack) {
    assert(stack);
    stack->_arr = (ElemType*)malloc(sizeof(ElemType) * 4);
    if (stack->_arr == NULL) {
        printf("初始化失败\n");
        exit(-1);
    }
    stack->_top = 0;
    stack->capacity = 4;
}

// 清空 -> 如果栈存在则清空
void StackClear(SeqStack* stack) {
    assert(stack);
    free(stack->_arr);
    stack->_arr = NULL;
    stack->_top = 0;
}

// 销毁 -> 如果栈存在则销毁
void StackDestroy(SeqStack* stack) {
    StackClear(stack);
    stack->capacity = 0;
}

// 返回1则栈空，返回0则栈非空
int StackEmpty(SeqStack* stack) {
    assert(stack);

    /*if (stack->_top == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }*/
    return stack->_top == 0 ? 1 : 0;
}

// 获取栈长度
int StackLength(SeqStack* stack) {
    assert(stack);
    return stack->_top;
}

// 获取栈顶元素
ElemType StackGetTop(SeqStack* stack) {
    assert(stack);
    assert(StackEmpty(stack) == 0);
    return stack->_arr[stack->_top - 1];
}

// 入栈
void StackPush(SeqStack* stack, ElemType data) {
    assert(stack);
    if (stack->_top == stack->capacity) {
        // 扩大二倍容器
        stack->capacity *= 2;
        ElemType* temp =
            (ElemType*)realloc(stack->_arr, sizeof(ElemType) * stack->capacity);
        if (temp == NULL) {
            printf("内存不足，入栈失败\n");
            exit(-1);
        } else {
            stack->_arr = temp;
        }
    }
    stack->_arr[stack->_top] = data;
    stack->_top++;
}

// 出栈
void StackPop(SeqStack* stack) {
    assert(stack);
    assert(StackEmpty(stack) == 0);
    stack->_top--;
}

typedef struct {
    SeqStack _pushStack;
    SeqStack _popStack;
} MyQueue;

// 返回队列开头的元素
int myQueuePeek(MyQueue* obj);

MyQueue* myQueueCreate() {
    MyQueue* queue = (MyQueue*)malloc(sizeof(MyQueue));
    if (queue == NULL) {
        exit(-1);
    }
    StackInint(&queue->_pushStack);
    StackInint(&queue->_popStack);
    return queue;
}

void myQueuePush(MyQueue* obj, int x) { StackPush(&obj->_pushStack, x); }

int myQueuePop(MyQueue* obj) {
    // 先取到队列开头元素，再弹出
    int ret = myQueuePeek(obj);
    StackPop(&obj->_popStack);
    return ret;
}

int myQueuePeek(MyQueue* obj) {
    if (StackEmpty(&obj->_popStack)) {
        // 如果_popStack空则将_pushStack的栈顶数据中的数据弹出并压入_popStack
        while (!StackEmpty(&obj->_pushStack)) {
            StackPush(&obj->_popStack, StackGetTop(&obj->_pushStack));
            StackPop(&obj->_pushStack);
        }
        return StackGetTop(&obj->_popStack);
    } else {
        // 如果_popStack中有数据则直接返回栈顶数据
        return StackGetTop(&obj->_popStack);
    }
}

bool myQueueEmpty(MyQueue* obj) {
    return StackEmpty(&obj->_pushStack) && StackEmpty(&obj->_popStack);
}

void myQueueFree(MyQueue* obj) {
    StackDestroy(&obj->_pushStack);
    StackDestroy(&obj->_popStack);
    free(obj);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);

 * int param_2 = myQueuePop(obj);

 * int param_3 = myQueuePeek(obj);

 * bool param_4 = myQueueEmpty(obj);

 * myQueueFree(obj);
*/