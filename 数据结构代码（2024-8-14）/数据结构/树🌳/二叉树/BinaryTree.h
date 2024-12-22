#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef char ElemType;

//二叉链表的结点
typedef struct BinaryNode
{
	ElemType _data;                  //数据域
	struct BinaryNode* _leftChild;   //左孩子指针
	struct BinaryNode* _rightChild;  //右孩子指针
}BinaryNode;

//创建新结点
BinaryNode* BinaryTreeCreateNode(ElemType data);

//根据先序遍历创建二叉树树
BinaryNode* BinaryTreeCreate(char* arr, int* pi);

//销毁
void BinaryTreeDestroy(BinaryNode* root);

//先序遍历
void PrevOrder(BinaryNode* root);

//中序遍历
void InOrder(BinaryNode* root);

//后序遍历
void PostOrder(BinaryNode* root);

//层序遍历
void LevelOrder(BinaryNode* root);

//树中的结点个数
int TreeSize(BinaryNode* root);

//树中叶子结点的个数
int TreeLeafSize(BinaryNode* root);

//二叉树第k层结点数目
int BinaryTreeLeaveKSize(BinaryNode* root, int k);

//查找X的结点
BinaryNode* BinaryTreeFind(BinaryNode* root, ElemType data);

//判断是否是完全二叉树
int BinaryTreeComplete(BinaryNode* root);




