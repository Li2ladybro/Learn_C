//#ifndef TITLE_CHECK_H
//#define TITLE_CHECK_H
//#include <graphics.h>                  //eaxyx必备头文件
//#include <conio.h>                     //控制台输入输出
//#include <iostream>                    //C++输入输出
//#include <string>                      //C++字符串
//#include <Windows.h>                   //API调用
//#include<mmsystem.h>                   //API媒体调用
//#pragma comment(lib,"winmm.lib")       //已导入静态库，可写可不写
//using namespace std;
//#define Old_File_Address "./旧题目.txt"
//#define New_File_Address "./新题目.txt"
////几张界面图纸
//static IMAGE sart_bk, middle_bk;
////标记是否需要刷新
//static int clear_flag = 0;
////按钮参数
//typedef struct Button
//{
//	int left;
//	int top;
//	int right;
//	int bottom;                //上下左右点的坐标
//	bool line;                 //是否启用边框 
//	COLORREF color_full;       //填充色 
//	COLORREF color_line;       //边框颜色 
//	string tcolor;             //字体颜色 
//	unsigned int r;            //圆半径，0的时候无圆角
//	bool T_flag;               //是否显示文字
//	TCHAR text[1000];          //按钮文字
//	int theight;               //字体高度
//	int twidth;                //字体宽度
//	int tsetoff;               //偏移量
//}Button;
//typedef struct File_data
//{
//	int  _Current_line_count;   //当前题目行数
//	int  _breadth;              //宽度
//	int  _capacity;             //容量大小
//	char(*_titles)[100];        //数据存储         
//}File_data;
///************************************************************************
////函数名：out_button
////参数：按钮结构体
////返回值：void
////Function：按照结构体参数制作按钮
//************************************************************************/
//void out_button(Button btn);
//
///************************************************************************
////函数名：mouse
////参数：按钮结构体，整形按钮变化量
////返回值：int
////Function：如果点击按钮则返回0，否则返回-1
//************************************************************************/
//int mouse(Button btn, int change);
//
///************************************************************************
////函数名：file_add_over_flag
////参数：void
////返回类型：int
////Function：如果题目文件添加失败返回1，添加成功返回0
//************************************************************************/
//int file_add_over_flag();
//
///************************************************************************
////函数名：Inint_File_data
////参数：File_data*
////返回类型：void 
////Function：初始化文件数据
//************************************************************************/
//void Inint_File_data(File_data* ps);
//
///************************************************************************
////函数名：Write_File_To_Array
////参数：地址：文件；地址：存放地址
////返回类型：int
////Function：将题目写入数组并返回文件行数
//************************************************************************/
//int Write_File_To_Array(FILE* f, File_data* ps);
//
///************************************************************************
////函数名：acqure_max_repetition
////参数：void
////返回类型：int
////Function：设置最大重复率
//************************************************************************/
//int  acqure_max_repetition();
//
///************************************************************************
////函数名：drawGradientBar
////参数：int：上顶点坐标；int：进度条宽度；int：进度条宽度；增量
////返回值：void
////Function：绘制渐变色的进度条
//************************************************************************/
//void drawGradientBar(int x, int y, int width, int height, int progress);
//
///************************************************************************
////计算同一文件下的重复率
//// 函数名： se_file_caluatesimilarity
////参数：题目地址，整形：空白行数目，整形：题目数目（含空白行）
////返回类型：int
////Function：计算同一文件重复度
//************************************************************************/
////int se_file_caluatesimilarity(char title[M][N], int bk_count, int line_count);
//
//
//
//#endif