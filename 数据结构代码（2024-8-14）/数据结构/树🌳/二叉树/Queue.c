#include "Queue.h"

//��ʼ��������һ���յĶ���
void QueueInint(Queue* queue)
{
	assert(queue);
	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
	if (newnode == NULL)
	{
		printf("��ʼ��ʧ��\n");
		exit(-1);
	}
	newnode->next = NULL;
	//ͷ�ڵ�
	queue->head = queue->tail = newnode;
}

//��� -> ������д��������
void QueueClear(Queue* queue)
{
	assert(queue);
	if (queue->head == queue->tail)
	{
		//�����ѿ�
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

//���� -> ������д���������
void QueueDestroy(Queue* queue)
{
	//ͷβ�ÿ�
	assert(queue);
	QueueClear(queue);
	free(queue->head);
	queue->head = queue->tail = NULL;
}

//����1����пգ�����0����зǿ�
int QueueEmpty(Queue* queue)
{
	assert(queue);
	return queue->head == queue->tail ? 1 : 0;
}

//��ȡ���г���
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

//��ȡ����ͷԪ��
QueueDataElemType QueueFront(Queue* queue)
{
	assert(queue);
	assert(queue->head != queue->tail);
	return queue->head->next->data;
}

//��ȡ����βԪ��
QueueDataElemType QueueBack(Queue* queue)
{
	assert(queue);
	assert(queue->head != queue->tail);
	return queue->tail->data;
}

//�����
void QueuePush(Queue* queue, QueueDataElemType data)
{
	assert(queue);
	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
	if (newnode == NULL)
	{
		printf("�ڴ治�㣬���ʧ��\n");
		exit(-1);
	}
	newnode->data = data;
	newnode->next = NULL;

	queue->tail->next = newnode;
	queue->tail = newnode;
}

//������
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
		//�ն���
		queue->tail = queue->head;
	}
}

