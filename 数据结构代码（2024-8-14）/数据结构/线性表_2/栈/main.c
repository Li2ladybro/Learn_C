#include "Stack.h"

static void SeqStackTest()
{
	SeqStack stack;
	StackInint(&stack);
	StackPush(&stack, 1);
	StackPush(&stack, 2);

	printf("%d\n", StackGetTop(&stack));

	StackPop(&stack);
	StackPush(&stack, 3);
	StackPush(&stack, 4);
	StackPush(&stack, 5);
	/*while(StackLength(&stack))
	{
		printf("%d\n", StackGetTop(&stack));
		printf("|\n");
		StackPop(&stack);
	}
	printf("NULL");*/
	
	while (!StackEmpty(&stack))
	{
		printf("%d\n", StackGetTop(&stack));
		printf("|\n");
		StackPop(&stack);
	}
	printf("NULL");

	StackDestroy(&stack);
}

int main()
{
	
	SeqStackTest();
	return 0;
}