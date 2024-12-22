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
		printf("-3�ڵ�%d��λ����\n", SeqListFind(&sl, -3) + 1);
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
		printf("δ�ҵ�ɾ��ʧ��\n");
	}
	SeqListPrint(&sl);

	SeqListInsert(&sl, 10000000, 2);
	SeqListPrint(&sl);
	SeqListErase(&sl, 1);
	SeqListPrint(&sl);
	SeqListDestory(&sl);
	return 0;
}

 