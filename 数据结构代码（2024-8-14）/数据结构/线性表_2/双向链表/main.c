#include"LinkList.h"

void LinkListTest1()
{
	LinkListNode* phead = ListInit();
	ListPushBack(phead, 1);
	ListPushBack(phead, 2);
	ListPushBack(phead, 3);
	ListPushBack(phead, 4);
	ListPrint(phead);

	ListPopBack(phead);
	ListPopBack(phead);
	ListPopBack(phead);

	ListPrint(phead);

	ListDestroy(&phead);





}

void LinkListTest2()
{
	LinkListNode* phead = ListInit();

	ListPushFront(phead, 1);
	ListPushFront(phead, 2);
	ListPushFront(phead, 3);
	ListPushFront(phead, 4);
	ListPrint(phead);

	ListPopFront(phead);
	ListPopFront(phead);
	ListPopFront(phead);
	

	ListPrint(phead);
	ListDestroy(&phead);

}

void LinkListTest3()
{

	LinkListNode* phead = ListInit();
	ListPushFront(phead, 1);
	ListPushFront(phead, 2);
	ListPushFront(phead, 3);
	ListPushFront(phead, 4);
	ListPrint(phead);

	LinkListNode* pos = ListFind(phead, 3);
	//LinkListNode* pos = ListFind(phead, 10);
	printf("%p\n", pos);
	ListInsert(pos, 100);
	ListPrint(phead);
	pos->data = 10000000000;
	ListPrint(phead);
	ListErase(pos);
	ListPrint(phead);

	ListDestroy(&phead);



}
int main()
{

	LinkListTest1();
	//LinkListTest2();
	//LinkListTest3();

	return 0;
}