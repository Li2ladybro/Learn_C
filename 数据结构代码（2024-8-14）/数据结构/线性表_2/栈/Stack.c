#include"Stack.h"

//初始化 -> 构建一个空的顺序栈
void StackInint(SeqStack* stack)
{
	assert(stack);
	stack->_arr = (ElemType*)malloc(sizeof(ElemType) * 4);
	if (stack->_arr == NULL)
	{
		printf("初始化失败\n");
		exit(-1);
	}
	stack->_top = 0;
	stack->_capacity = 4;
}

//清空 -> 如果栈存在则清空
void StackClear(SeqStack* stack)
{
	assert(stack);
	free(stack->_arr);
	stack->_arr = NULL;
	stack->_top = 0;
}

//销毁 -> 如果栈存在则销毁
void StackDestroy(SeqStack* stack)
{
	StackClear(stack);
	stack->_capacity = 0;
}

//返回1则栈空，返回0则栈非空
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

//获取栈长度
int StackLength(SeqStack* stack)
{
	assert(stack);
	return stack->_top;
}

//获取栈顶元素
ElemType StackGetTop(SeqStack* stack)
{
	assert(stack);
	assert(StackEmpty(stack) == 0);
	return stack->_arr[stack->_top-1];
}

//入栈
void StackPush(SeqStack* stack, ElemType data)
{
	assert(stack);
	if (stack->_top == stack->_capacity)
	{
		//扩大二倍容器
		stack->_capacity *=2 ;
		ElemType* temp = (ElemType*)realloc(stack->_arr, sizeof(ElemType) * stack->_capacity);
		if (temp == NULL)
		{
			printf("内存不足，入栈失败\n");
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

//出栈
void StackPop(SeqStack* stack)
{
	assert(stack);
	assert(StackEmpty (stack) == 0);
	stack->_top--;
}






