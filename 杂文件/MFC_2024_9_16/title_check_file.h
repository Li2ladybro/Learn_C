/************************************************************************
�ļ������Ŀ⺯��
************************************************************************/

#pragma once

#include <stdio.h>  //�������
#include <stdlib.h> //��̬�ڴ濪��
#include <string.h> //memset��������

typedef struct file_data {
    int _current_line_count; // ��ǰ��Ŀ����
    int _breadth;            // ���
    int _capacity;           // ������С
    char (*_titles)[100];    // ���ݴ洢
} file_data;

/************************************************************************
//��������init_file_data
//������file_data*
//�������ͣ�void
//Function����ʼ���ļ�����
************************************************************************/
void init_file_data(file_data* ps);

/************************************************************************
//��������write_file_to_array
//��������ַ���ļ�����ַ����ŵ�ַ
//�������ͣ�void
//Function������Ŀд�����鲢�����ļ�����
************************************************************************/
void write_file_to_array(FILE* f, file_data* ps);

/************************************************************************
//��������bk_caluate
//��������ַ������
//����ֵ������
//Function��ͳ�ƿհ���
************************************************************************/
int bk_caluate(file_data* ps);

/************************************************************************
//����ͬһ�ļ��µ��ظ���
//�������� se_file_caluatesimilarity
//������File_data* ����Ŀ��ַ; int���հ�����Ŀ
//�������ͣ�int
//Function������ͬһ�ļ��ظ���
************************************************************************/
int se_file_caluatesimilarity(file_data* ps, int bk_count);

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
//������const file_data* ������Ŀ��ַ��const file_data* ������Ŀ��ַ;
//      FILE* ��Ҫд���ļ����ļ�ָ��;
//      const int������ظ���;
//      char* ���Ƿ���Ҫ�����ļ�����;
//      const int������Ŀ�ļ��հ��У�const int������Ŀ�ļ��ظ���;
//      const int������Ŀ�ļ��հ��У�const int������Ŀ�ļ��ظ���;
//
//�������ͣ�void
//Function���ó����ؽ�����ѽ��д��Output_file.txt�ļ�
************************************************************************/
void obtaine_check_result_and_write_to_file(
    const file_data* oldtitle, const file_data* newtitle, FILE* pi,
    const int& max_repetition, const char* if_self_check,
    const int& old_bk_count, const int& old_se_file_similarity,
    const int& new_bk_count, const int& new_se_file_similarity);