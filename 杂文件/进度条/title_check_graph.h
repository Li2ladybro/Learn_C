#pragma once
#include <graphics.h>
/************************************************************************
//函数名：drawGradientBar
//参数：int：上顶点坐标；int：进度条宽度；int：进度条宽度；增量
//返回值：void
//Function：绘制渐变色的进度条
************************************************************************/
void drawGradientBar(int x, int y, int width, int height, int progress);

/************************************************************************
//函数名：draw_progress_bar
//参数：int 窗口宽度；int 窗口高度
//返回类型：void 
//Function：绘画进度条
************************************************************************/
void draw_progress_bar(int width, int height);
