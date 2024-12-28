#include <graphics.h>
#include <conio.h>
#include <iostream>
#include <string>
#include <Windows.h>
#include<mmsystem.h>
#pragma comment(lib,"winmm.lib")         //已导入静态库，可写可不写
using namespace std;
//按钮参数
typedef struct Button
{
	int left;
	int top;
	int right;
	int bottom;                //上下左右点的坐标
	bool line;                 //是否启用边框 
	COLORREF color_full;       //填充色 
	COLORREF color_line;       //边框颜色 
	string tcolor;             //字体颜色 
	unsigned int r;            //圆半径，0的时候无圆角
	bool T_flag;               //是否显示文字
	TCHAR text[1000];          //按钮文字
	int theight;               //字体高度
	int twidth;                //字体宽度
	int tsetoff;               //偏移量
}Button;
//鼠标交互
int mouse(Button btn, int change);
//制作按钮
void out_long(Button btn);
//开始界面
IMAGE sart_bk,middle_bk;
//标记是否需要刷新
int clear_flag = 0;  
int main()
{
	initgraph(1365, 658);
	setbkcolor(BLUE);
	cleardevice();                  //清下屏
	loadimage(&sart_bk,L"res\\start_bk.png", 1365, 658);//从资源文件载入图片到sart_bk
	putimage(0, 0, &sart_bk);
	TCHAR tex1[1000] = _T("Entre");
	//带边框,且填充内部颜色，还加了边框色,设置了边角的半径,Enter
	Button btn = { 280,400,550,480,0,RGB(215,232,250),GREEN,"blue",20,1,_T("Entre"),40,20,20};
	out_long(btn);
	while (1)
	{
		
		if (!(mouse(btn, 10)))
		{
			break;
		}
		else
			continue;
	}

	loadimage(&middle_bk, L"res\\middle_bk.jpg", 1920, 1440);    //从资源文件载入图片到middle_bk
	putimage(0, 0, &middle_bk);

	system("pause");
	closegraph();
	return 0;
}
int mouse(Button btn, int change)
{
	//设置按钮交互响应
	ExMessage m;                        //定义一个消息变量息
	m = getmessage(EM_MOUSE);           //获取鼠标消息  
	switch (m.message)
	{
    //鼠标移动到按钮时按钮变大
	case WM_MOUSEMOVE:
		if (m.x >= btn.left && m.x <= btn.right && m.y >= btn.top && m.y <= btn.bottom)
		{
			clear_flag = 1;
			btn.left = btn.left - change;
			btn.top -= change;
			btn.right += change;
			btn.bottom += change;
			out_long(btn);
			return -1;
		}
		else
		{
			if (clear_flag == 1)
			{
				int pts[] = { btn.left - change ,btn.top - change,  btn.right + change,btn.bottom + change };
				clearpolygon((POINT*)pts, 4);
				//cleardevice();
				//loadimage(&sart_bk, L"res\\start_bk.png", 1365, 658);//从资源文件载入图片到bk
				putimage(0, 0, &sart_bk);
				out_long(btn);
				clear_flag = 0;
				return -1;
			}
			return -1;

		}
    //鼠标点击按钮退出循环
	case WM_LBUTTONDOWN:
		if (m.x >= btn.left && m.x <= btn.right && m.y >= btn.top && m.y <= btn.bottom)
		{
			clear_flag = 1;
			btn.left   = btn.left - change;
			btn.top    -= change;
			btn.right   += change;
			btn.bottom  += change;
			out_long(btn);
			mciSendString(_T("open res\\button_click _sound.mp3 alias music"), NULL, 0, NULL);     //alias是别名的意思，下面就可以去直接用music来代替kk.mp3
			mciSendString(_T("play music"), NULL, 0, NULL);          //播放音乐
			return 0;
		}
		else
		{

			if (clear_flag == 1)
			{
				int pts[] = { btn.left - change ,btn.top- change,  btn.right+ change,btn.bottom+ change  };
				clearpolygon((POINT*)pts, 4);
				//cleardevice();
				//loadimage(&sart_bk, L"res\\start_bk.png", 1365, 658);//从资源文件载入图片到bk
				putimage(0, 0, &sart_bk);
				out_long(btn);
				clear_flag = 0;
				return -1;
			}
			return -1;
		}
	}
}
void out_long(Button btn)
{
	setlinecolor(btn.color_line);  // 设置当前线条颜色 
	setfillcolor(btn.color_full);  // 设置当前填充颜色 
	if (!btn.r)
	{
		//如果没有半径，就是输出普通长方体
		if (btn.line)//如果有边框
			fillrectangle(btn.left, btn.top, btn.right, btn.bottom);
		else
			solidrectangle(btn.left, btn.top, btn.right, btn.bottom);
	}
	else
	{   //输出带圆角长方体
		if (btn.line)
		{
			//如果有边框
			fillcircle(btn.left + btn.r, btn.top + btn.r, btn.r);
			fillcircle(btn.left + btn.r, btn.bottom - btn.r, btn.r);
			fillcircle(btn.right - btn.r, btn.top + btn.r, btn.r);
			fillcircle(btn.right - btn.r, btn.bottom - btn.r, btn.r);
			solidrectangle(btn.left, btn.top + btn.r, btn.right, btn.bottom - btn.r);
			solidrectangle(btn.left + btn.r, btn.top, btn.right - btn.r, btn.bottom);
			::line(btn.left + btn.r, btn.top, btn.right - btn.r, btn.top);
			::line(btn.left + btn.r, btn.bottom, btn.right - btn.r, btn.bottom);
			::line(btn.left, btn.top + btn.r, btn.left, btn.bottom - btn.r);
			::line(btn.right, btn.top + btn.r, btn.right, btn.bottom - btn.r);
		}
		else
		{
			solidrectangle(btn.left, btn.top + btn.r, btn.right, btn.bottom - btn.r);
			solidrectangle(btn.left + btn.r, btn.top, btn.right - btn.r, btn.bottom);
			solidcircle(btn.left + btn.r, btn.top + btn.r, btn.r);
			solidcircle(btn.left + btn.r, btn.bottom - btn.r, btn.r);
			solidcircle(btn.right - btn.r, btn.top + btn.r, btn.r);
			solidcircle(btn.right - btn.r, btn.bottom - btn.r, btn.r);
		}
	}
	if (btn.T_flag == 1)
	{
		//设置字体
		setbkmode(TRANSPARENT);//设置透明字体
		if (btn.tcolor == "red" || btn.tcolor == "RED")
		{
			settextcolor(RED);//设置字体颜色为红色
		}
		else if (btn.tcolor == "green" || btn.tcolor == "GREEN")
		{
			settextcolor(GREEN);//设置字体颜色为红色
		}
		else if (btn.tcolor == "blue" || btn.tcolor == "BLUE")
		{
			settextcolor(BLUE);//设置字体颜色为红色
		}
		else if (btn.tcolor == "yellow" || btn.tcolor == "YELLOW")
		{
			settextcolor(YELLOW);//设置字体颜色为黄色
		}
		else if (btn.tcolor == "black" || btn.tcolor == "BLACK")
		{
			settextcolor(BLACK);//设置字体颜色为黑色
		}
		else if (btn.tcolor == "white" || btn.tcolor == "WHITE")
		{
			settextcolor(WHITE);//设置字体颜色为白色
		}

		else
		{
			int x;
			x = MessageBox(GetForegroundWindow(),
				TEXT("请检查按钮边框颜色是否设置正确，目前字体颜色包含：red、green、blue、yellow、black、white。"),
				TEXT("按钮边框颜色设置错误"), 1);
			cout << x;
		}
		//设置字体格式
		settextstyle(btn.theight, btn.twidth, _T("宋体"));
		outtextxy(btn.left + btn.tsetoff, btn.top + btn.tsetoff, btn.text);//设置显示位置
	}
}