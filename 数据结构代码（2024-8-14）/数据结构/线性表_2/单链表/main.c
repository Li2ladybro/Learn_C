#include "SLinkList.h"



int main()
{
	/********************************************************************************
	���ﶨ����һ��ָ��һ�����ֵ����SLinkListNode���͵�ָ�루��ַ��
	********************************************************************************/
	SLinkListNode* phead;

	/********************************************************************************
    ���ﴫ��phead�����ĵ�ַ��Ŀ���ǰѱ���phead��ֵ����ַ���޸�Ϊͷ���ĵ�ַ��������ͷָ��ָ��ͷ��㣩
	ʵ�ֳ�ʼ����ʱpheadָ���SLinkListNode���������ֵ��ͷ��㣬��ʱͷ���ĵ�ַ����phead
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
		printf("û���ҵ�\n");
	}
	if (SLinkListFind(phead, 1))
	{
		SLinkListFind(phead, 1)->date = 10;
	}
	else
	{
		printf("û���ҵ�\n");
	}
	SLinkListInsertAfter(&phead,phead, 90);
	SLinkListPrint(phead);

	SLinkListEraseAfter(&phead, phead);



	SLinkListPrint(phead);


	return 0;


}