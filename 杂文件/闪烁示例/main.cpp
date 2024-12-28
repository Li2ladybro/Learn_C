//#include<graphics.h>
//#include<conio.h>
//#include<string>
//#include<Windows.h>
//#include<iostream>
//using namespace std;
//
//struct Button
//{
//	int x1;
//	int x2;
//	int y1;
//	int y2;
//};
//
//void setVertexAndShowButton(Button btn, int x1, int x2, int y1, int y2, TCHAR text[1000], int tlength, int twidth, int tsetoff, string tcolor, string lcolor, string fcolor)
//{
//	BeginBatchDraw();//暂停绘画
//	//设置顶点坐标
//	btn.x1 = x1;
//	btn.x2 = x2;
//	btn.y1 = y1;
//	btn.y2 = y2;
//	//设置边框颜色
//	if (lcolor == "red" || lcolor == "RED")setlinecolor(RED);//设置边框颜色为红色
//	else if (lcolor == "green" || lcolor == "GREEN")setlinecolor(GREEN);//设置边框颜色为红色
//	else if (lcolor == "blue" || lcolor == "BLUE")setlinecolor(BLUE);//设置边框颜色为红色
//	else if (lcolor == "yellow" || lcolor == "YELLOW")setlinecolor(YELLOW);//设置边框颜色为黄色
//	else if (lcolor == "black" || lcolor == "BLACK")setlinecolor(BLACK);//设置边框颜色为黑色
//	else if (lcolor == "white" || lcolor == "WHITE")setlinecolor(WHITE);//设置边框颜色为白色
//	else {
//		int x;
//		x = MessageBox(GetForegroundWindow(),
//			TEXT("请检查按钮边框颜色是否设置正确，目前字体颜色包含：red、green、blue、yellow、black、white。"), 
//			TEXT("按钮边框颜色设置错误"), 1);
//		cout << x;
//	}
//	//绘制按钮边框
//	//rectangle(btn.x1, btn.y1, btn.x2, btn.y2);
//	//设置填充颜色
//	if (fcolor == "red" || fcolor == "RED")setfillcolor(RED);//设置填充颜色为红色
//	else if (fcolor == "green" || fcolor == "GREEN")setfillcolor(GREEN);//设置填充颜色为红色
//	else if (fcolor == "blue" || fcolor == "BLUE")setfillcolor(BLUE);//设置填充颜色为红色
//	else if (fcolor == "yellow" || fcolor == "YELLOW")setfillcolor(YELLOW);//设置填充颜色为黄色
//	else if (fcolor == "black" || fcolor == "BLACK")setfillcolor(BLACK);//设置填充颜色为黑色
//	else if (fcolor == "white" || fcolor == "WHITE")setfillcolor(WHITE);//设置填充颜色为白色
//	else {
//		int x;
//		x = MessageBox(GetForegroundWindow(),
//			TEXT("请检查按钮填充颜色是否设置正确，目前填充颜色包含：red、green、blue、yellow、black、white。"), TEXT("按钮填充颜色设置错误"), 1);
//		cout << x;
//	}
//	fillrectangle(btn.x1, btn.y1, btn.x2, btn.y2);
//	//设置按钮文字
//	setbkmode(TRANSPARENT);//设置透明字体
//
//	if (tcolor == "red" || tcolor == "RED")settextcolor(RED);//设置字体颜色为红色
//	else if (tcolor == "green" || tcolor == "GREEN")settextcolor(GREEN);//设置字体颜色为红色
//	else if (tcolor == "blue" || tcolor == "BLUE")settextcolor(BLUE);//设置字体颜色为红色
//	else if (tcolor == "yellow" || tcolor == "YELLOW")settextcolor(YELLOW);//设置字体颜色为黄色
//	else if (tcolor == "black" || tcolor == "BLACK")settextcolor(BLACK);//设置字体颜色为黑色
//	else if (tcolor == "white" || tcolor == "WHITE")settextcolor(WHITE);//设置字体颜色为白色
//	else {
//		int x;
//		x = MessageBox(GetForegroundWindow(), TEXT("请检查字体颜色是否设置正确，目前字体颜色包含：red、green、blue、yellow、black、white。"), TEXT("字体颜色设置错误"), 1);
//		cout << x;
//	}
//	//settextcolor(BLUE);//设置字体颜色
//	settextstyle(tlength, twidth, _T("宋体"));//设置字体格式
//	outtextxy(x1 + tsetoff, y1 + tsetoff, text);//设置显示位置
//
//
//	//设置按钮交互响应
//	//MOUSEMSG m;// 定义鼠标消息
//	int change = 10;
//	ExMessage m;//定义一个消息变量
//	m = getmessage(EM_MOUSE);//获取鼠标消息
//	switch (m.message)
//	{
//	case WM_MOUSEMOVE:
//		// 鼠标移动按钮时按钮变大
//		if (m.x >= btn.x1 && m.x <= btn.x2)
//		{
//			if (m.y >= btn.y1 && m.y <= btn.y2)
//			{
//				roundrect(
//					btn.x1 - change, btn.y1 - change, btn.x2 + change, btn.y2 + change,60,60);
//				fillrectangle(btn.x1 - change, btn.y1 - change, btn.x2 + change, btn.y2 + change);
//				 
//			}
//			else
//			{
//				FlushBatchDraw();//批量绘制
//				//cleardevice();
//			}
//		}
//		else
//		{
//			FlushBatchDraw();//批量绘制
//			//cleardevice();
//		}
//		break;
//
//	case WM_LBUTTONDOWN:
//		// 鼠标点击按钮会变绿色
//		if (m.x >= btn.x1 && m.x <= btn.x2)
//		{
//			if (m.y >= btn.y1 && m.y <= btn.y2)
//			{
//				setfillcolor(GREEN);
//				fillrectangle(btn.x1, btn.y1, btn.x2, btn.y2);
//
//				FlushBatchDraw();//批量绘制
//			}
//			else
//			{
//				FlushBatchDraw();//批量绘制
//				//cleardevice();
//			}
//		}
//		break;
//	}
//
//	//恢复画线和填充颜色
//	setlinecolor(WHITE);
//	setfillcolor(WHITE);
//}
//
//int main()
//{
//	Button btns[3]; //初始化按钮结构体数组
//
//	initgraph(640, 480);//初始化界面
//
//	TCHAR tex1[1000] = _T("按钮1");
//	TCHAR tex2[1000] = _T("按钮2");
//	TCHAR tex3[1000] = _T("按钮3");
//
//	while (1)
//	{
//		setVertexAndShowButton(btns[0], 280, 360, 220, 260, tex1, 20, 10, 5, "green", "green", "red");
//
//		setVertexAndShowButton(btns[1], 280, 360, 270, 310, tex2, 20, 10, 5, "white", "green", "red");
//
//		setVertexAndShowButton(btns[2], 280, 360, 320, 360, tex3, 20, 10, 5, "YELLOW", "green", "red");
//	}
//
//	_getch();//等待用户输入
//
//	return 0;
//}
#include <graphics.h>
#include <conio.h>
void out_long
(//制作长方体，圆角长方体
	int left,
	int top,
	int right,
	int bottom,       //上下左右点的坐标
	bool line = false,             //是否启用边框,默认不用
	COLORREF color_full = WHITE,   //填充色(默认为白)
	COLORREF color_line = BLACK,   //边框颜色(默认为黑)
	unsigned int r = 0    //圆半径，0的时候无圆角
)
{
	setlinecolor(color_line);  // 设置当前线条颜色 
	setfillcolor(color_full);  // 设置当前填充颜色 
	if (!r) {//如果没有半径，就是输出普通长方体
		if (line)//如果有边框
			fillrectangle(left, top, right, bottom);
		else
			solidrectangle(left, top, right, bottom);
	}
	else {//输出带圆角长方体
		if (line) {//如果有边框
			fillcircle(left + r, top + r, r);
			fillcircle(left + r, bottom - r, r);
			fillcircle(right - r, top + r, r);
			fillcircle(right - r, bottom - r, r);
			solidrectangle(left, top + r, right, bottom - r);
			solidrectangle(left + r, top, right - r, bottom);
			::line(left + r, top, right - r, top);
			::line(left + r, bottom, right - r, bottom);
			::line(left, top + r, left, bottom - r);
			::line(right, top + r, right, bottom - r);
		}
		else {
			solidrectangle(left, top + r, right, bottom - r);
			solidrectangle(left + r, top, right - r, bottom);
			solidcircle(left + r, top + r, r);
			solidcircle(left + r, bottom - r, r);
			solidcircle(right - r, top + r, r);
			solidcircle(right - r, bottom - r, r);
		}
	}
}
int main() {
	initgraph(500, 500);
	setbkcolor(0xfffff1);
	cleardevice();//清下屏
	out_long(10, 10, 50, 50);//默认输出
	out_long(10, 60, 50, 100, true);//带边框
	out_long(10, 110, 50, 150, true, 0xAAAAAA);//带边框,且填充内部颜色
	out_long(10, 160, 50, 200, true, 0x00Bfff, 0xFF3030);//带边框,且填充内部颜色，还加了边框色
	out_long(10, 210, 50, 250, true, 0xffffff, 0xFF3030, 20);//带边框,且填充内部颜色，还加了边框色,设置了边角的半径
	//吐槽：一个像圆的圆角长方体
	out_long(10, 260, 200, 400, true, 0xAAAAAA, 0xADFF2F, 20);//带边框,且填充内部颜色，还加了边框色,设置了边角的半径
	//正常了
	out_long(10, 410, 400, 490, true, 0xf0f0f0, 0x87CEFA, 20);//带边框,且填充内部颜色，还加了边框色,设置了边角的半径
	_getch();//不过不行就换成getch();
	closegraph();
	return 0;
}
