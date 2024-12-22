#include"BinaryTree.h"

//�������
BTNode* CreateNode(Elemtype data)
{
	BTNode* newNode = (BTNode*)malloc(sizeof(BTNode));
	if (newNode == NULL)
	{
		printf("�ڴ治��\n");
		exit(-1);
	}
	newNode->_data = data;
	newNode->_leftChild = newNode->_rightChild = NULL;
	return newNode;
}

//�����������������������
BTNode* CreateTree(char* arr, int* pi)
{
	if (arr[(*pi)] == '#')
	{
		/*BTNode* newNode = CreateNode(arr[(*pi)]);
		(*pi)++;
		return newNode;*/


		//���ؿս��
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

//�������
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

//�������
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

//����
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