#pragma once
#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>    //输入输出
#include<stdlib.h>   //动态内存开辟
#include<string.h>   //memset函数调用
#define _CRT_SECURE_NO_DEPRECATE
#define Old_File_Address "./旧题目.txt"
#define New_File_Address "./新题目.txt"
typedef struct File_data
{
    int  _Current_line_count;   //当前题目行数
    int  _breadth;              //宽度
    int  _capacity;             //容量大小
    char(*_titles)[100];       //数据存储         
}File_data;

/************************************************************************
//函数名：Inint_File_data
//参数：File_data*
//返回类型：void
//Function：初始化文件数据
************************************************************************/
void Inint_File_data(File_data* ps);

/************************************************************************
//函数名：Write_File_To_Array
//参数：地址：文件；地址：存放地址
//返回类型：int
//Function：将题目写入数组并返回文件行数
************************************************************************/
int Write_File_To_Array(FILE* f, File_data* ps);