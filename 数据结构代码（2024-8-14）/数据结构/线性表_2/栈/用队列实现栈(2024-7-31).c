#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//存储结构
typedef int ElemType;

typedef struct QueueNode
{
	ElemType data;
	struct QueueNode* next;
}QueueNode;

//先入先出（FIFO）

typedef struct Queue
{
	QueueNode* head;
	QueueNode* tail;
}Queue;

//初始化，构建一个空的队列
void QueueInint(Queue* queue);

//清空 -> 如果队列存在则清空
void QueueClear(Queue* queue);

//销毁 -> 如果队列存在则销毁
void QueueDestroy(Queue* queue);

//返回1则队列空，返回0则队列非空
int QueueEmpty(Queue* queue);

//获取队列长度
int QueueLength(Queue* queue);

//获取队列头元素
ElemType QueueFront(Queue* queue);

//获取队列尾元素
ElemType QueueBack(Queue* queue);

//入队列
void QueuePush(Queue* queue, ElemType data);

//出队列
void QueuePop(Queue* queue);

//初始化，构建一个空的队列
void QueueInint(Queue* queue)
{
	assert(queue);
	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
	if (newnode == NULL)
	{
		printf("初始化失败\n");
		exit(-1);
	}
	newnode->next = NULL;
	//头节点
	queue->head = queue->tail = newnode;
}

//清空 -> 如果队列存在则清空
void QueueClear(Queue* queue)
{
	assert(queue);
	if (queue->head == queue->tail)
	{
		//队列已空
		return;
	}
	assert(queue->head != queue->tail);
	QueueNode* head = queue->head;
	QueueNode* cur = head->next;
	QueueNode* next = cur->next;
	while (cur !=NULL)
	{
		free(cur);
		cur = next;
		if (next)
		{
			next = next->next;
		}
	}
}

//销毁 -> 如果队列存在则销毁
void QueueDestroy(Queue* queue)
{
	//头尾置空
	assert(queue);
	QueueClear(queue);
	free(queue->head);
	queue->head = queue->tail = NULL;
}

//返回1则队列空，返回0则队列非空
int QueueEmpty(Queue* queue)
{
	assert(queue);
	return queue->head == queue->tail ? 1 : 0;
}

//获取队列长度
int QueueLength(Queue* queue)
{
	assert(queue);
	QueueNode* cur = queue->head->next;
	int length = 0;
	while (cur != NULL)
	{		
		length++;
		cur = cur->next;
	}
	return length;
}

//获取队列头元素
ElemType QueueFront(Queue* queue)
{
	assert(queue);
	assert(queue->head != queue->tail);
	return queue->head->next->data;
}

//获取队列尾元素
ElemType QueueBack(Queue* queue)
{
	assert(queue);
	assert(queue->head != queue->tail);
	return queue->tail->data;
}

//入队列
void QueuePush(Queue* queue, ElemType data)
{
	assert(queue);
	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
	if (newnode == NULL)
	{
		printf("内存不足，入队失败\n");
		exit(-1);
	}
	newnode->data = data;
	newnode->next = NULL;

	queue->tail->next = newnode;
	queue->tail = newnode;
}

//出队列
void QueuePop(Queue* queue)
{
	assert(queue);
	assert(queue->head != queue->tail);

	QueueNode* first = queue->head->next;
	QueueNode* second = first->next;

	queue->head->next = second;
	free(first);

	if (second == NULL)
	{
		//空队列
		queue->tail = queue->head;
	}
}

typedef struct 
{
Queue _q1;
Queue _q2; 
} MyStack;


MyStack* myStackCreate() 
{
    /*
    Queue q1;
    Queue q2;
    QueueInint(q1);
    QueueInint(q2);*/
    MyStack* stack=(MyStack*)malloc(sizeof(MyStack));
    QueueInint(&stack->_q1);
    QueueInint(&stack->_q2);
    /*
    stack->_q1=q1;
    stack->_q2=q2;*/
    return stack;
}

void myStackPush(MyStack* obj, int x) 
{
    if(QueueEmpty(&obj->_q1)!=1)
    {
        QueuePush(&obj->_q1,x);
    }
    else
    {
        QueuePush(&obj->_q2,x);
    }
}

int myStackPop(MyStack* obj) 
{
    //默认_q1为空，_q2不为空
    Queue* empty=&obj->_q1;
    Queue* nonempty=&obj->_q2;
    if(QueueEmpty(&obj->_q2))//_q2为空
    {
        //交换
        empty=&obj->_q2;
        nonempty=&obj->_q1;
    }
        //若_q1非空，将_q1弹出至只剩队尾，并将弹出的元素保留在另一个队列（_q2）中
        while(QueueLength(nonempty)>1)
        {
            QueuePush(empty,QueueFront(nonempty));
            QueuePop(nonempty);
        }
        int pop=QueueBack(nonempty);
        QueuePop(nonempty);
    return pop;
}

int myStackTop(MyStack* obj) {
    if(QueueEmpty(&obj->_q1)!=1)
    {
        return QueueBack(&obj->_q1);
    }
    else{
        return QueueBack(&obj->_q2);
    }
}

bool myStackEmpty(MyStack* obj) {
    return QueueEmpty(&obj->_q1)&&QueueEmpty(&obj->_q2);
}

void myStackFree(MyStack* obj) {
    QueueDestroy(&obj->_q1);
    QueueDestroy(&obj->_q2);
    free(obj);
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