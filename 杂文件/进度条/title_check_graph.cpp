#include"title_check_string.h"
#include"title_check_graph.h"
//��������drawGradientBar
//������int���϶������ꣻint����������ȣ�int����������ȣ�����
//����ֵ��void
//Function�����ƽ���ɫ�Ľ�����
void drawGradientBar(int x, int y, int width, int height, int progress)
{
    // ������ɫ��������
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
//��������draw_progress_bar
//������int ���ڿ�ȣ�int ���ڸ߶�
//�������ͣ�void 
//Function���滭������
void draw_progress_bar(int width, int height)
{
    // �������Ĳ���
    int barWidth = 500;
    int barHeight = 20;
    int barX = (width - barWidth) / 2;
    int barY = (height - barHeight) / 2;
    int progress = 0;
    int step = 10;
    // ���ƽ���������
    setlinecolor(RGB(180, 180, 180));
    rectangle(barX, barY, barX + barWidth, barY + barHeight);
    // ���ƽ�����
    drawGradientBar(barX, barY, barWidth, barHeight, progress);
    // ���½�����
    while (progress < barWidth)
    {
        // �ȴ�һ��ʱ��
        Sleep(100);
        // ���½�����
        progress += step;
        if (progress > barWidth) progress = barWidth;
        // ����ɵĽ�����
        drawGradientBar(barX, barY, barWidth, barHeight, progress - step);
        // �����µĽ�����
        drawGradientBar(barX, barY, barWidth, barHeight, progress);
        int process = (int)((double)progress / barWidth * 100);
        //int->string->wstring
        wstring s = string_To_wstring(to_string(process));
        //wstring->wchar_t*
        wchar_t* buffer = &s[0];
        outtextxy(barX, barY - 15, buffer);
    }
}