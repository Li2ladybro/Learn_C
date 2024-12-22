#pragma once

#include<stdio.h>
#include<stdlib.h>

typedef char Elemtype;

typedef struct BTNode
{
	Elemtype _data;
	struct BTNode* _leftChild;
	struct BTNode* _rightChild;
}BTNode;

//�������
BTNode* CreateNode(Elemtype data);

//�����������������������
BTNode* CreateTree(char* arr, int* pi);

//�������
void PrevOrderPrint(BTNode* root);

//�������
void InOrderPrint(BTNode* root);

//����
void BinaryTreeDestroy(BTNode* root);