#pragma once
#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>    //�������
#include<stdlib.h>   //��̬�ڴ濪��
#include<string.h>   //memset��������
#define _CRT_SECURE_NO_DEPRECATE
#define Old_File_Address "./����Ŀ.txt"
#define New_File_Address "./����Ŀ.txt"
typedef struct File_data
{
    int  _Current_line_count;   //��ǰ��Ŀ����
    int  _breadth;              //���
    int  _capacity;             //������С
    char(*_titles)[100];       //���ݴ洢         
}File_data;

/************************************************************************
//��������Inint_File_data
//������File_data*
//�������ͣ�void
//Function����ʼ���ļ�����
************************************************************************/
void Inint_File_data(File_data* ps);

/************************************************************************
//��������Write_File_To_Array
//��������ַ���ļ�����ַ����ŵ�ַ
//�������ͣ�int
//Function������Ŀд�����鲢�����ļ�����
************************************************************************/
int Write_File_To_Array(FILE* f, File_data* ps);