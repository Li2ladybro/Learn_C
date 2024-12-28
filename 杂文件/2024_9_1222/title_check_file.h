/************************************************************************
�ļ������Ŀ⺯��
************************************************************************/

#pragma once

#include<stdio.h>    //�������
#include<stdlib.h>   //��̬�ڴ濪��
#include<string.h>   //memset��������

#define Old_File_Address "./����Ŀ.txt"
#define New_File_Address "./����Ŀ.txt"

typedef struct File_data
{
    int  _current_line_count;   //��ǰ��Ŀ����
    int  _breadth;              //���
    int  _capacity;             //������С
    char(*_titles)[100];        //���ݴ洢
}File_data;

/************************************************************************
//��������inint_file_data
//������File_data*
//�������ͣ�void
//Function����ʼ���ļ�����
************************************************************************/
void inint_file_data(File_data* ps);

/************************************************************************
//��������write_file_to_array
//��������ַ���ļ�����ַ����ŵ�ַ
//�������ͣ�int
//Function������Ŀд�����鲢�����ļ�����
************************************************************************/
void write_file_to_array(FILE* f, File_data* ps);

/************************************************************************
//��������bk_caluate
//��������ַ������
//����ֵ������
//Function��ͳ�ƿհ���
************************************************************************/
int bk_caluate(File_data* ps);

/************************************************************************
//����ͬһ�ļ��µ��ظ���
//�������� se_file_caluatesimilarity
//������File_data* ����Ŀ��ַ; int���հ�����Ŀ
//�������ͣ�int
//Function������ͬһ�ļ��ظ���
************************************************************************/
int se_file_caluatesimilarity(File_data* ps, int bk_count);

/************************************************************************
//���㲻ͬ��Ŀ���ظ���
//��������dt_file_caluatesimilarity
//��������ַ
//�������ͣ�int
//Function�����㲻ͬ�ļ��ظ���
************************************************************************/
int dt_file_caluatesimilarity(char oldtitle[], char newtitle[]);

/************************************************************************
//��������obtaine_check_result_and_write_to_file
//������File_data* ������Ŀ��ַ;File_data* ������Ŀ��ַ;FILE* ��Ҫд���ļ��ĵ�ַ��int������ظ��� ;
//      int�����ļ��հ���;int�����ļ��ظ���;int�����ļ��հ���;int�����ļ��հ���;int�����ļ��ظ���
//�������ͣ�void
//Function���ó����ؽ�����ѽ��д��Output_file.txt�ļ�
************************************************************************/
void obtaine_check_result_and_write_to_file
(
    File_data* oldtitle,
    File_data* newtitle, 
    FILE* pi,
    int max_repetition,
    int old_bk_count,
    int old_se_file_similarity,
    int new_bk_count,            
    int new_se_file_similarity 
);

