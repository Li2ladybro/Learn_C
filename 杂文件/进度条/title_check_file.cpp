#include"title_check_file.h"

//��������Inint_File_data
//������File_data*
//�������ͣ�void 
//Function����ʼ���ļ�����
void Inint_File_data(File_data* ps)
{
    ps->_breadth = 100;
    ps->_capacity = 500;
    ps->_titles = (char(*)[100])malloc(sizeof(char) * ps->_capacity * ps->_breadth);
    if (ps->_titles == NULL)
    {
        printf("����ռ�ʧ�ܣ��˳�����\n");
        exit(1);
    }
    else
    {
        memset(ps->_titles, 0, sizeof(char) * ps->_capacity * ps->_breadth);
        ps->_Current_line_count = 0;
    }
}

//��������Write_File_To_Array
//��������ַ���ļ�����ַ����ŵ�ַ
//�������ͣ�int
//Function������Ŀд�����鲢�����ļ�����
int Write_File_To_Array(FILE* f, File_data* ps)
{
    int rank = 0;
    int forcecasting = 0;
    while ((forcecasting = fgetc(f)) != EOF)
    {
        if (forcecasting == '\n')
        {
            ps->_Current_line_count++;
        }

    }
    printf("�ļ�һ��%d��\n", ps->_Current_line_count);
    rewind(f);
    if (ps->_capacity < ps->_Current_line_count++)
    {
        ps->_capacity *= 2;
        realloc(ps->_titles, sizeof(char) * ps->_capacity * ps->_breadth);
        printf("���ڴ濪�ٳɹ�\n");
    }
    for (rank = 0; rank < ps->_Current_line_count; rank++)
    {
        fgets((ps->_titles)[rank], 100, f);
    }
    return ps->_Current_line_count;
}