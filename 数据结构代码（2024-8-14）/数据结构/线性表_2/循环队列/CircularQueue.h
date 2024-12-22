#pragma once

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);

 * bool param_2 = myCircularQueueDeQueue(obj);

 * int param_3 = myCircularQueueFront(obj);

 * int param_4 = myCircularQueueRear(obj);

 * bool param_5 = myCircularQueueIsEmpty(obj);

 * bool param_6 = myCircularQueueIsFull(obj);

 * myCircularQueueFree(obj);
*/

typedef int ElemType;

//循环队列存储结构
typedef struct 
{
	ElemType* _arr;    //顺序存储
	int _front;        //队头下标
	int _rear;         //队尾
	int _maxSize;      //最大空间有效数据位为_maxSize-1
} MyCircularQueue;

//构造器，设置队列长度为 k
MyCircularQueue* myCircularQueueCreate(int k);

//向循环队列插入一个元素。如果成功插入则返回真
int myCircularQueueEnQueue(MyCircularQueue* obj, ElemType value);

//从循环队列中删除一个元素。如果成功删除则返回真。
int myCircularQueueDeQueue(MyCircularQueue* obj);

//Front: 从队首获取元素。如果队列为空，返回 - 1 。
int myCircularQueueFront(MyCircularQueue* obj);

//Rear: 获取队尾元素。如果队列为空，返回 - 1 。
int myCircularQueueRear(MyCircularQueue* obj);

//isEmpty() : 检查循环队列是否为空。
int myCircularQueueIsEmpty(MyCircularQueue* obj);

//isFull() : 检查循环队列是否已满。
int myCircularQueueIsFull(MyCircularQueue* obj);

//销毁
void myCircularQueueFree(MyCircularQueue* obj);

