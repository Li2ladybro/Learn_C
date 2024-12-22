#pragma once
 
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

extern struct BinaryNode;

//存储结构
typedef struct BinaryNode* QueueDataElemType;  // 存结点的指针，结构体太大了

typedef struct QueueNode
{
	QueueDataElemType data;
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
QueueDataElemType QueueFront(Queue* queue);

//获取队列尾元素
QueueDataElemType QueueBack(Queue* queue);

//入队列
void QueuePush(Queue* queue, QueueDataElemType data);

//出队列
void QueuePop(Queue* queue);
