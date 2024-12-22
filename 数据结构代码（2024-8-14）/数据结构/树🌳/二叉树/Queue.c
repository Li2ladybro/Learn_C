#include "Queue.h"

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
QueueDataElemType QueueFront(Queue* queue)
{
	assert(queue);
	assert(queue->head != queue->tail);
	return queue->head->next->data;
}

//获取队列尾元素
QueueDataElemType QueueBack(Queue* queue)
{
	assert(queue);
	assert(queue->head != queue->tail);
	return queue->tail->data;
}

//入队列
void QueuePush(Queue* queue, QueueDataElemType data)
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

