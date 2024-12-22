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

//创建结点
BTNode* CreateNode(Elemtype data);

//根据先序遍历创建二叉树树
BTNode* CreateTree(char* arr, int* pi);

//先序遍历
void PrevOrderPrint(BTNode* root);

//中序遍历
void InOrderPrint(BTNode* root);

//销毁
void BinaryTreeDestroy(BTNode* root);