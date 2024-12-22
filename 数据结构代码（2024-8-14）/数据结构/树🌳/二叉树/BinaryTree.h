#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef char ElemType;

//��������Ľ��
typedef struct BinaryNode
{
	ElemType _data;                  //������
	struct BinaryNode* _leftChild;   //����ָ��
	struct BinaryNode* _rightChild;  //�Һ���ָ��
}BinaryNode;

//�����½��
BinaryNode* BinaryTreeCreateNode(ElemType data);

//�����������������������
BinaryNode* BinaryTreeCreate(char* arr, int* pi);

//����
void BinaryTreeDestroy(BinaryNode* root);

//�������
void PrevOrder(BinaryNode* root);

//�������
void InOrder(BinaryNode* root);

//�������
void PostOrder(BinaryNode* root);

//�������
void LevelOrder(BinaryNode* root);

//���еĽ�����
int TreeSize(BinaryNode* root);

//����Ҷ�ӽ��ĸ���
int TreeLeafSize(BinaryNode* root);

//��������k������Ŀ
int BinaryTreeLeaveKSize(BinaryNode* root, int k);

//����X�Ľ��
BinaryNode* BinaryTreeFind(BinaryNode* root, ElemType data);

//�ж��Ƿ�����ȫ������
int BinaryTreeComplete(BinaryNode* root);




