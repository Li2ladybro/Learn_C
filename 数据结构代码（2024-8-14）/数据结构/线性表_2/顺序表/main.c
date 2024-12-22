#include "SeqList.h"

int main()
{
	SeqList sl ;
	SeqListInit(&sl);
	SeqListPushBack(&sl, 1);
	SeqListPushBack(&sl, 2);
	SeqListPushBack(&sl,3);
	SeqListPushFront(&sl, -1);
	SeqListPushFront(&sl, -2);
	SeqListPushFront(&sl, -3);
	SeqListPrint(&sl);
	if(SeqListFind(&sl, -3)!=-1)
	{
		printf("-3在第%d个位置上\n", SeqListFind(&sl, -3) + 1);
	}
	int pos = SeqListFind(&sl, 1);
	if (pos != -1)
	{
		SeqListErase(&sl, pos);
	}
	SeqListPrint(&sl);
	pos = SeqListFind(&sl,0);
	if (pos != -1)
	{
		SeqListErase(&sl, pos);
	}
	else
	{
		printf("未找到删除失败\n");
	}
	SeqListPrint(&sl);

	SeqListInsert(&sl, 10000000, 2);
	SeqListPrint(&sl);
	SeqListErase(&sl, 1);
	SeqListPrint(&sl);
	SeqListDestory(&sl);
	return 0;
}

 