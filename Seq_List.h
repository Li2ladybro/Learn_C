#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int elemtype;
typedef struct Seq_list
{
	elemtype* elem;
	int size;//��¼��ǰ˳�����ЧԪ��
	int capicity;//�ܵ�������С
}Seq_list;
//��ʼ��˳���
void Inint_Seq_list(Seq_list* ps);
//�ݻ�˳���
void Destory_Seq_List(Seq_list* ps);
//����
void Check_Capicity(Seq_list* ps);
//��ӡ˳���
void Print_Seq_List(Seq_list* ps);
//β��Ԫ��
void Push_Back_SeqList(Seq_list* ps,elemtype x);
//βɾԪ��
void Pop_Back_SeqList(Seq_list* ps);
//ͷ��Ԫ��
void Push_front_SeqList(Seq_list* ps, elemtype x);
//ͷɾԪ��
void Pop_front_SeqList(Seq_list* ps);
//����Ԫ��
void Insert_SeqList(Seq_list* ps, int pos, elemtype x);
//ɾ��Ԫ��
void Delete_SeqList(Seq_list* ps, elemtype x);
//����
void Find_elem(Seq_list* ps, elemtype x);
