#include"Stack.h"

//��ʼ�� -> ����һ���յ�˳��ջ
void StackInint(SeqStack* stack)
{
	assert(stack);
	stack->_arr = (ElemType*)malloc(sizeof(ElemType) * 4);
	if (stack->_arr == NULL)
	{
		printf("��ʼ��ʧ��\n");
		exit(-1);
	}
	stack->_top = 0;
	stack->_capacity = 4;
}

//��� -> ���ջ���������
void StackClear(SeqStack* stack)
{
	assert(stack);
	free(stack->_arr);
	stack->_arr = NULL;
	stack->_top = 0;
}

//���� -> ���ջ����������
void StackDestroy(SeqStack* stack)
{
	StackClear(stack);
	stack->_capacity = 0;
}

//����1��ջ�գ�����0��ջ�ǿ�
int StackEmpty(SeqStack* stack)
{
	assert(stack);
	
	/*if (stack->_top == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}*/
	return stack->_top==0 ? 1:0;
}

//��ȡջ����
int StackLength(SeqStack* stack)
{
	assert(stack);
	return stack->_top;
}

//��ȡջ��Ԫ��
ElemType StackGetTop(SeqStack* stack)
{
	assert(stack);
	assert(StackEmpty(stack) == 0);
	return stack->_arr[stack->_top-1];
}

//��ջ
void StackPush(SeqStack* stack, ElemType data)
{
	assert(stack);
	if (stack->_top == stack->_capacity)
	{
		//�����������
		stack->_capacity *=2 ;
		ElemType* temp = (ElemType*)realloc(stack->_arr, sizeof(ElemType) * stack->_capacity);
		if (temp == NULL)
		{
			printf("�ڴ治�㣬��ջʧ��\n");
			exit(-1);
		}
		else
		{
			stack->_arr = temp;
		}
		
	}
	stack->_arr[stack->_top] = data;
	stack->_top++;
}

//��ջ
void StackPop(SeqStack* stack)
{
	assert(stack);
	assert(StackEmpty (stack) == 0);
	stack->_top--;
}






