#include"title_check_file.h"

//函数名：Inint_File_data
//参数：File_data*
//返回类型：void 
//Function：初始化文件数据
void Inint_File_data(File_data* ps)
{
    ps->_breadth = 100;
    ps->_capacity = 500;
    ps->_titles = (char(*)[100])malloc(sizeof(char) * ps->_capacity * ps->_breadth);
    if (ps->_titles == NULL)
    {
        printf("申请空间失败，退出程序\n");
        exit(1);
    }
    else
    {
        memset(ps->_titles, 0, sizeof(char) * ps->_capacity * ps->_breadth);
        ps->_Current_line_count = 0;
    }
}

//函数名：Write_File_To_Array
//参数：地址：文件；地址：存放地址
//返回类型：int
//Function：将题目写入数组并返回文件行数
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
    printf("文件一共%d行\n", ps->_Current_line_count);
    rewind(f);
    if (ps->_capacity < ps->_Current_line_count++)
    {
        ps->_capacity *= 2;
        realloc(ps->_titles, sizeof(char) * ps->_capacity * ps->_breadth);
        printf("新内存开辟成功\n");
    }
    for (rank = 0; rank < ps->_Current_line_count; rank++)
    {
        fgets((ps->_titles)[rank], 100, f);
    }
    return ps->_Current_line_count;
}