#include"BinaryTree.h"

//创建结点
BTNode* CreateNode(Elemtype data)
{
	BTNode* newNode = (BTNode*)malloc(sizeof(BTNode));
	if (newNode == NULL)
	{
		printf("内存不足\n");
		exit(-1);
	}
	newNode->_data = data;
	newNode->_leftChild = newNode->_rightChild = NULL;
	return newNode;
}

//根据先序遍历创建二叉树树
BTNode* CreateTree(char* arr, int* pi)
{
	if (arr[(*pi)] == '#')
	{
		/*BTNode* newNode = CreateNode(arr[(*pi)]);
		(*pi)++;
		return newNode;*/


		//返回空结点
		(*pi)++;
		return NULL;
	}
	else
	{
		BTNode* root = CreateNode(arr[(*pi)++]);
		root->_leftChild = CreateTree(arr, pi);
		root->_rightChild = CreateTree(arr, pi);
		return root;
	}
}

//先序遍历
void PrevOrderPrint(BTNode* root)
{
	/*
	if (root ->_data== '#')
	{
		printf("%c ",'#');
		return;
	}
	*/

	if (root == NULL)
	{
		printf("%c ", '#');
		return;
	}
	else
	{
		printf("%c ", root->_data);
		PrevOrderPrint(root->_leftChild);
		PrevOrderPrint(root->_rightChild);
		return;
	}
}

//中序遍历
void InOrderPrint(BTNode* root)
{
	/*
	if (root ->_data== '#')
	{
		printf("%c ",'#');
		return;
	}
	*/

	if (root == NULL)
	{
		printf("%c ", '#');
		return;
	}
	InOrderPrint(root->_leftChild);
	printf("%c ", root->_data);
	InOrderPrint(root->_rightChild);
	return;
}

//销毁
void BinaryTreeDestroy(BTNode* root)
{
	/*
	if (root->_data == '#')
	{
		free(root);
	}*/
	if (root == NULL)
	{
		return;
	}
	else
	{
		BinaryTreeDestroy(root->_leftChild);
		BinaryTreeDestroy(root->_rightChild);
		free(root);
	}
}