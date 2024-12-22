#include"BinaryTree.h"

/*
BinaryNode* BinaryTreeCreate()
{
	BinaryNode* rA = CreateNode('A');
	BinaryNode* rB = CreateNode('B');
	BinaryNode* rC = CreateNode('C');
	BinaryNode* rD = CreateNode('D');
	BinaryNode* rE = CreateNode('E');
	rA->_leftChild = rB;
	rA->_rightChild = rC;

	rB->_rightChild = rE;

	return rA;
}
*/

void BinaryTreeOrderTest()
{
	
	//BinaryNode* rA = BinaryTreeCreate();
	char* arr = "abd##e##c##";
	int i = 0;
	BinaryNode* rA=BinaryTreeCreate(arr, &i);
	printf("先序遍历：\n");
	PrevOrder(rA);
	printf("\n");
	printf("中序遍历：\n");
	InOrder(rA);
	printf("\n");
	printf("后序遍历：\n");
	PostOrder(rA);
	printf("\n");
	printf("层序遍历：\n");
	LevelOrder(rA);
	printf("\n");

	BinaryTreeDestroy(rA);
}

void BinaryTreeNodeTest()
{
	char* arr = "abbcb38*#ssc###########";
	int i = 0;
	BinaryNode* rA = BinaryTreeCreate(arr, &i);
	printf("\n");

	printf("先序遍历：\n");
	PrevOrder(rA);
	printf("\n");
	printf("中序遍历：\n");
	InOrder(rA);
	printf("\n");
	printf("后序遍历：\n");
	PostOrder(rA);
	printf("\n");
	printf("层序遍历：\n");
	LevelOrder(rA);
	printf("\n");

	//BinaryNode* rA = BinaryTreeCreate();
	printf("\n");

	printf("rA树的结点数目为：%d", TreeSize(rA));
	printf("\n");

	printf("rA树的叶子结点数目为：%d", TreeLeafSize(rA));
	printf("\n");

	int k = 3;
	printf("第%d层结点个数为%d\n", k, BinaryTreeLeaveKSize(rA, k));
	k = 2;
	printf("第%d层结点个数为%d\n", k, BinaryTreeLeaveKSize(rA, k));
	k = 1;
	printf("第%d层结点个数为%d\n", k, BinaryTreeLeaveKSize(rA, k));

	char findData = 'a';
	BinaryNode* findAddress = BinaryTreeFind(rA, findData);

	if (findAddress != NULL)
	{
		printf("%c数据结点所在的地址为%p\n", findData, findAddress);
		findAddress->_data = '$';
		printf("修改之后的数值为%c,地址为%p\n", findAddress->_data, findAddress);
	}
	else
	{
		printf("未找到\n" );
	}

	BinaryTreeDestroy(rA);

}

void BinaryTreeTest()
{
	char* arr = "ab#d$#2!@4%#c########";
	int i = 0;
	BinaryNode* rA = BinaryTreeCreate(arr, &i);

	printf("\n");

	printf("先序遍历：\n");
	PrevOrder(rA);
	printf("\n");
	printf("中序遍历：\n");
	InOrder(rA);
	printf("\n");
	printf("后序遍历：\n");
	PostOrder(rA);
	printf("\n");
	printf("层序遍历：\n");
	LevelOrder(rA);
	printf("\n");

	//BinaryNode* rA = BinaryTreeCreate();
	printf("\n");

	if (BinaryTreeComplete(rA))
	{
		printf("该🌳是完全二叉树\n");
	}

	else
	{
		printf("该🌳不是完全二叉树\n");
	}

	BinaryTreeDestroy(rA);

}

int main()
{
	BinaryTreeOrderTest();
	BinaryTreeNodeTest();
	BinaryTreeTest();
	return 0;
}

