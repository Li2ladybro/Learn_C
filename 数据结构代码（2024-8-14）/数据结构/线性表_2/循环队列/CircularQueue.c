#include "CircularQueue.h"

//构造器，设置队列长度为 k
MyCircularQueue* myCircularQueueCreate(int k)
{
	MyCircularQueue* cirQueue = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
	if (cirQueue == NULL)
	{
		printf("初始化失败，内存不足\n");
		exit(-1);
	}
	cirQueue->_maxSize = k + 1;    //有效数据为K个
	cirQueue->_arr = (int*)malloc(sizeof(int) * cirQueue->_maxSize);
	if (cirQueue->_arr == NULL)
	{
		printf("初始化失败，内存不足\n");
		exit(-1);
	}
	cirQueue->_front = cirQueue->_rear = 0;
	return cirQueue;
}

//向循环队列插入一个元素。如果成功插入则返回真
int myCircularQueueEnQueue(MyCircularQueue* obj, ElemType value)
{
	if (myCircularQueueIsFull(obj))
	{
		//队列满插入失败
		printf("队列满插入失败\n");
		return 0;
	}
	else
	{
		//队列不满插入成功
		obj->_arr[obj->_rear] = value;
		obj->_rear = (obj->_rear + 1) % obj->_maxSize;
		return 1;
	}
}

//从循环队列中删除一个元素。如果成功删除则返回真。
int myCircularQueueDeQueue(MyCircularQueue* obj) 
{
	if (myCircularQueueIsEmpty(obj))
	{
		//队列为空删除失败
		printf("队列为空删除失败\n");
		return 0;
	}
	else
	{
		//队列非空删除成功
		obj->_front =(obj->_front+1)% obj->_maxSize;
		return 1;
	}
}

//Front: 从队首获取元素。如果队列为空，返回 - 1 。
int myCircularQueueFront(MyCircularQueue* obj) 
{
	if (myCircularQueueIsEmpty(obj) == 1)
	{
		return -1;
	}
	else
	{
		return obj->_arr[obj->_front];
	}
}

//Rear: 获取队尾元素。如果队列为空，返回 - 1 。
int myCircularQueueRear(MyCircularQueue* obj) 
{
	if (myCircularQueueIsEmpty(obj) == 1)
	{
		return -1;
	}
	else
	{
		int ret = 0;
		if (obj->_rear - 1 == -1)
		{
			ret = obj->_maxSize - 1;
		}
		else
		{
			ret = obj->_rear - 1;
		}
		return obj->_arr[ret];
	}
}

//isEmpty() : 检查循环队列是否为空。
int myCircularQueueIsEmpty(MyCircularQueue* obj) 
{
	if (obj->_rear == obj->_front)
	{
		//🈳队列
		return 1;
	}
	else
	{
		//非空
		return 0;
	}
}

//isFull() : 检查循环队列是否已满。
int myCircularQueueIsFull(MyCircularQueue* obj) 
{
	if ((obj->_rear + 1) % obj->_maxSize == obj->_front)
	{
		return 1;
	}
	else
	{
		//非空
		return 0;
	}
}

//销毁
void myCircularQueueFree(MyCircularQueue* obj) 
{
	free(obj->_arr);
	free(obj);
}

