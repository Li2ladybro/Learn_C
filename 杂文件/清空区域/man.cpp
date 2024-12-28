#include<graphics.h>
#include<conio.h>
int main()
{
	initgraph(640, 480);
	setbkcolor(WHITE);//设置背景为白色
	cleardevice();//用背景色清空屏幕
	int san[] = { 80,5,10,100,100,100 };
	int san1[] = { 80,30,70,40,60,80,40,90 };
	setfillcolor(RED);//设置颜色
	setlinecolor(GREEN);//边框的颜色是绿色
	fillpolygon((POINT*)san, 3);//有边框有填充的三角形
	clearpolygon((POINT*)san1, 4);//清空不规则四边形
	_getch();
	closegraph();//关闭窗口
	return 0;
}
