#include "SLinkList.h"



int main()
{
	/********************************************************************************
	这里定义了一个指向一个随机值数据SLinkListNode类型的指针（地址）
	********************************************************************************/
	SLinkListNode* phead;

	/********************************************************************************
    这里传入phead变量的地址，目的是把变量phead的值（地址）修改为头结点的地址（即将此头指针指向头结点）
	实现初始化此时phead指向的SLinkListNode不再是随机值是头结点，此时头结点的地址就是phead
	********************************************************************************/
	
	SLinkListInit(&phead);
	SLinkListPushBack(&phead, 1);
	SLinkListPushBack(&phead, 2);
	SLinkListPushBack(&phead, 3);
	SLinkListPushBack(&phead, 4);
	SLinkListPopBack(&phead);
	SLinkListPopBack(&phead);
	SLinkListPopBack(&phead);
	


	SLinkListPrint(phead);

	SLinkListPushFront(&phead, 1);
	SLinkListPushFront(&phead, 2);
	SLinkListPushFront(&phead, 3);
	SLinkListPushFront(&phead, 4);
	SLinkListPrint(phead);

	SLinkListPopFront(&phead);
	SLinkListPrint(phead);
	SLinkListPopFront(&phead);
	SLinkListPopFront(&phead);
	if (SLinkListFind(phead, 1))
	{
		SLinkListFind(phead, 1)->date = 10;
	}
	else
	{
		printf("没有找到\n");
	}
	if (SLinkListFind(phead, 1))
	{
		SLinkListFind(phead, 1)->date = 10;
	}
	else
	{
		printf("没有找到\n");
	}
	SLinkListInsertAfter(&phead,phead, 90);
	SLinkListPrint(phead);

	SLinkListEraseAfter(&phead, phead);



	SLinkListPrint(phead);


	return 0;


}