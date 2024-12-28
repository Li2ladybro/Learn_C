#include"title_check_string.h"
#include"title_check_graph.h"
//函数名：drawGradientBar
//参数：int：上顶点坐标；int：进度条宽度；int：进度条宽度；增量
//返回值：void
//Function：绘制渐变色的进度条
void drawGradientBar(int x, int y, int width, int height, int progress)
{
    // 定义颜色渐变数组
    int gradientColors[] = { RGB(255, 0, 0), RGB(255, 255, 0), RGB(0, 255, 0), RGB(0, 255, 255), RGB(0, 0, 255), RGB(75, 0, 130) };
    for (int i = 0; i < height; i++)
    {
        double ratio = (double)i / height;
        COLORREF color = RGB
        (
            (int)(gradientColors[0] * (1 - ratio) + gradientColors[1] * ratio),
            (int)(gradientColors[3] * (1 - ratio) + gradientColors[4] * ratio),
            (int)(gradientColors[2] * (1 - ratio) + gradientColors[5] * ratio)
        );
        setfillcolor(color);
        solidrectangle(x, y + i, x + progress, y + i + 1);
    }
}
//函数名：draw_progress_bar
//参数：int 窗口宽度；int 窗口高度
//返回类型：void 
//Function：绘画进度条
void draw_progress_bar(int width, int height)
{
    // 进度条的参数
    int barWidth = 500;
    int barHeight = 20;
    int barX = (width - barWidth) / 2;
    int barY = (height - barHeight) / 2;
    int progress = 0;
    int step = 10;
    // 绘制进度条背景
    setlinecolor(RGB(180, 180, 180));
    rectangle(barX, barY, barX + barWidth, barY + barHeight);
    // 绘制进度条
    drawGradientBar(barX, barY, barWidth, barHeight, progress);
    // 更新进度条
    while (progress < barWidth)
    {
        // 等待一段时间
        Sleep(100);
        // 更新进度条
        progress += step;
        if (progress > barWidth) progress = barWidth;
        // 清除旧的进度条
        drawGradientBar(barX, barY, barWidth, barHeight, progress - step);
        // 绘制新的进度条
        drawGradientBar(barX, barY, barWidth, barHeight, progress);
        int process = (int)((double)progress / barWidth * 100);
        //int->string->wstring
        wstring s = string_To_wstring(to_string(process));
        //wstring->wchar_t*
        wchar_t* buffer = &s[0];
        outtextxy(barX, barY - 15, buffer);
    }
}