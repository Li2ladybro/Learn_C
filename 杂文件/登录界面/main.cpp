#include<stdio.h>
#include<windows.h>//gotoxy
#include<conio.h>//getch
#include<string.h>//strcmp
#define ROW 14
#define COL 14

void gotoxy(int x, int y)//形参
{
	HANDLE hOut;
	COORD pos = { x,y };
	// 光标的起始位（第1列，第3行） 0是第1列 2是第3行
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOut, pos);
	//printf("定位光标位置搜索(%d,%d)\n",pos.X,pos.Y);
}

void paintWindow()       //用户登录窗口
{
	int startX = 6;
	int startY = 5;
	int width = 20;
	int height = 20;
	int i = 0;
	//打印顶部   
	//光标定位 找规律 ┗  ┛ ┏ ┓ ┃ ━
	//顶部 y不变 x 在变 (x-x+w)
	gotoxy(startX, startY);
	printf("┏");
	for (i = 0; i < width - 2; i++)  //控制循环次数width-2次
	{
		printf("━ ");
	}
	printf("┓");
	//左边 x不变 y在变 (y到y+height)
	for (i = 1; i <= height - 2; i++)
	{
		gotoxy(startX, startY + i);
		printf("┃");
	}

	//右边 x不变 =startx+width-1  y在变 y 到 y+height
	for (i = 1; i <= height - 2; i++)
	{
		gotoxy(startX + width * 2 - 3, startY + i);
		printf("┃");
	}
	//底部 x在变化    y不变 （x到x+width） ━ 
	gotoxy(startX, startY + height - 1);
	printf("┗");
	for (i = 0; i < width - 2; i++)
	{
		printf("━ ");
	}
	printf("┛");

	gotoxy(startX, startX + height);
}

void login()     //用户登录界面
{
	char ch = 0;
	int i = 0;
	char name[9] = { 0 };//字符数组部分初始化
	char pwd[9] = { 0 };//字符数组部分初始化
	//绘制一个窗口
	paintWindow();
	//绘制标题 标签
	gotoxy(21, 9);
	printf("登录窗口");

	gotoxy(6 + 5, 12);
	printf("账号：");

	gotoxy(6 + 5, 16);
	printf("密码：");

	gotoxy(18, 12);//光标定位在用户名输入的位置
	//用户名的输入 存储
	while (1)
	{
		ch = _getch();
		if (ch == '\r' && i == 0)  //任何内容都没输
		{
			continue;
		}
		if (ch == '\r' && i > 0 || i == 8)  //长度最多八位
		{
			break;
		}
		if (ch >= '0' && ch <= '9' || ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z')
		{
			_putch(ch);
			name[i] = ch;
			++i;
		}
	}

	gotoxy(18, 16); //光标定位在密码输入的位置
	i = 0;//使用同一个计数器 需要重置
	//密码输入 存储
	while (1)
	{
		ch = _getch();
		if (ch == '\r' && i == 0)  //任何内容都没输
		{
			continue;
		}
		if (ch == '\r' && i > 0 || i == 8)  //长度最多八位
		{
			break;
		}
		if (ch >= '0' && ch <= '9' || ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z')
		{
			_putch('*');
			pwd[i] = ch;
			++i;
		}
	}

	gotoxy(15, 18);  //显示登录成功 登录失败
	if (strcmp(name, "admin") == 0 && strcmp(pwd, "123456") == 0)
	{
		printf("登录成功\n");
	}
	else
	{
		printf("登录失败\n");
	}

	gotoxy(0, 27);

	//登录验证  admin 123456
}

int main()
{
	login();
	return 0;
}