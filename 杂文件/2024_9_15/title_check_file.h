/************************************************************************
文件操作的库函数
************************************************************************/

#pragma once

#include<stdio.h>    //输入输出
#include<stdlib.h>   //动态内存开辟
#include<string.h>   //memset函数调用

#define Old_File_Address "./旧题目.txt"
#define New_File_Address "./新题目.txt"

typedef struct File_data
{
    int  _current_line_count;   //当前题目行数
    int  _breadth;              //宽度
    int  _capacity;             //容量大小
    char(*_titles)[100];        //数据存储
}File_data;

/************************************************************************
//函数名：inint_file_data
//参数：File_data*
//返回类型：void
//Function：初始化文件数据
************************************************************************/
void inint_file_data(File_data* ps);

/************************************************************************
//函数名：write_file_to_array
//参数：地址：文件；地址：存放地址
//返回类型：int
//Function：将题目写入数组并返回文件行数
************************************************************************/
void write_file_to_array(FILE* f, File_data* ps);

/************************************************************************
//函数名：bk_caluate
//参数：地址，整型
//返回值：整型
//Function：统计空白行
************************************************************************/
int bk_caluate(File_data* ps);

/************************************************************************
//计算同一文件下的重复率
//函数名： se_file_caluatesimilarity
//参数：File_data* ：题目地址; int：空白行数目
//返回类型：int
//Function：计算同一文件重复度
************************************************************************/
int se_file_caluatesimilarity(File_data* ps, int bk_count);

/************************************************************************
//计算不同题目的重复率
//函数名：dt_file_caluatesimilarity
//参数：地址
//返回类型：int
//Function：计算不同文件重复率
************************************************************************/
int dt_file_caluatesimilarity(char oldtitle[], char newtitle[]);

/************************************************************************
//函数名：obtaine_check_result_and_write_to_file
//参数：File_data* ：旧题目地址;File_data* ：新题目地址;FILE* ：要写入文件的地址；int：最大重复率 ;
//      int：旧文件空白行;int：旧文件重复度;int：新文件空白行;int：旧文件空白行;int：旧文件重复度
//返回类型：void
//Function：得出查重结果并把结果写入Output_file.txt文件
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

