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
//	BeginBatchDraw();//��ͣ�滭
//	//���ö�������
//	btn.x1 = x1;
//	btn.x2 = x2;
//	btn.y1 = y1;
//	btn.y2 = y2;
//	//���ñ߿���ɫ
//	if (lcolor == "red" || lcolor == "RED")setlinecolor(RED);//���ñ߿���ɫΪ��ɫ
//	else if (lcolor == "green" || lcolor == "GREEN")setlinecolor(GREEN);//���ñ߿���ɫΪ��ɫ
//	else if (lcolor == "blue" || lcolor == "BLUE")setlinecolor(BLUE);//���ñ߿���ɫΪ��ɫ
//	else if (lcolor == "yellow" || lcolor == "YELLOW")setlinecolor(YELLOW);//���ñ߿���ɫΪ��ɫ
//	else if (lcolor == "black" || lcolor == "BLACK")setlinecolor(BLACK);//���ñ߿���ɫΪ��ɫ
//	else if (lcolor == "white" || lcolor == "WHITE")setlinecolor(WHITE);//���ñ߿���ɫΪ��ɫ
//	else {
//		int x;
//		x = MessageBox(GetForegroundWindow(),
//			TEXT("���鰴ť�߿���ɫ�Ƿ�������ȷ��Ŀǰ������ɫ������red��green��blue��yellow��black��white��"), 
//			TEXT("��ť�߿���ɫ���ô���"), 1);
//		cout << x;
//	}
//	//���ư�ť�߿�
//	//rectangle(btn.x1, btn.y1, btn.x2, btn.y2);
//	//���������ɫ
//	if (fcolor == "red" || fcolor == "RED")setfillcolor(RED);//���������ɫΪ��ɫ
//	else if (fcolor == "green" || fcolor == "GREEN")setfillcolor(GREEN);//���������ɫΪ��ɫ
//	else if (fcolor == "blue" || fcolor == "BLUE")setfillcolor(BLUE);//���������ɫΪ��ɫ
//	else if (fcolor == "yellow" || fcolor == "YELLOW")setfillcolor(YELLOW);//���������ɫΪ��ɫ
//	else if (fcolor == "black" || fcolor == "BLACK")setfillcolor(BLACK);//���������ɫΪ��ɫ
//	else if (fcolor == "white" || fcolor == "WHITE")setfillcolor(WHITE);//���������ɫΪ��ɫ
//	else {
//		int x;
//		x = MessageBox(GetForegroundWindow(),
//			TEXT("���鰴ť�����ɫ�Ƿ�������ȷ��Ŀǰ�����ɫ������red��green��blue��yellow��black��white��"), TEXT("��ť�����ɫ���ô���"), 1);
//		cout << x;
//	}
//	fillrectangle(btn.x1, btn.y1, btn.x2, btn.y2);
//	//���ð�ť����
//	setbkmode(TRANSPARENT);//����͸������
//
//	if (tcolor == "red" || tcolor == "RED")settextcolor(RED);//����������ɫΪ��ɫ
//	else if (tcolor == "green" || tcolor == "GREEN")settextcolor(GREEN);//����������ɫΪ��ɫ
//	else if (tcolor == "blue" || tcolor == "BLUE")settextcolor(BLUE);//����������ɫΪ��ɫ
//	else if (tcolor == "yellow" || tcolor == "YELLOW")settextcolor(YELLOW);//����������ɫΪ��ɫ
//	else if (tcolor == "black" || tcolor == "BLACK")settextcolor(BLACK);//����������ɫΪ��ɫ
//	else if (tcolor == "white" || tcolor == "WHITE")settextcolor(WHITE);//����������ɫΪ��ɫ
//	else {
//		int x;
//		x = MessageBox(GetForegroundWindow(), TEXT("����������ɫ�Ƿ�������ȷ��Ŀǰ������ɫ������red��green��blue��yellow��black��white��"), TEXT("������ɫ���ô���"), 1);
//		cout << x;
//	}
//	//settextcolor(BLUE);//����������ɫ
//	settextstyle(tlength, twidth, _T("����"));//���������ʽ
//	outtextxy(x1 + tsetoff, y1 + tsetoff, text);//������ʾλ��
//
//
//	//���ð�ť������Ӧ
//	//MOUSEMSG m;// ���������Ϣ
//	int change = 10;
//	ExMessage m;//����һ����Ϣ����
//	m = getmessage(EM_MOUSE);//��ȡ�����Ϣ
//	switch (m.message)
//	{
//	case WM_MOUSEMOVE:
//		// ����ƶ���ťʱ��ť���
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
//				FlushBatchDraw();//��������
//				//cleardevice();
//			}
//		}
//		else
//		{
//			FlushBatchDraw();//��������
//			//cleardevice();
//		}
//		break;
//
//	case WM_LBUTTONDOWN:
//		// �������ť�����ɫ
//		if (m.x >= btn.x1 && m.x <= btn.x2)
//		{
//			if (m.y >= btn.y1 && m.y <= btn.y2)
//			{
//				setfillcolor(GREEN);
//				fillrectangle(btn.x1, btn.y1, btn.x2, btn.y2);
//
//				FlushBatchDraw();//��������
//			}
//			else
//			{
//				FlushBatchDraw();//��������
//				//cleardevice();
//			}
//		}
//		break;
//	}
//
//	//�ָ����ߺ������ɫ
//	setlinecolor(WHITE);
//	setfillcolor(WHITE);
//}
//
//int main()
//{
//	Button btns[3]; //��ʼ����ť�ṹ������
//
//	initgraph(640, 480);//��ʼ������
//
//	TCHAR tex1[1000] = _T("��ť1");
//	TCHAR tex2[1000] = _T("��ť2");
//	TCHAR tex3[1000] = _T("��ť3");
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
//	_getch();//�ȴ��û�����
//
//	return 0;
//}
#include <graphics.h>
#include <conio.h>
void out_long
(//���������壬Բ�ǳ�����
	int left,
	int top,
	int right,
	int bottom,       //�������ҵ������
	bool line = false,             //�Ƿ����ñ߿�,Ĭ�ϲ���
	COLORREF color_full = WHITE,   //���ɫ(Ĭ��Ϊ��)
	COLORREF color_line = BLACK,   //�߿���ɫ(Ĭ��Ϊ��)
	unsigned int r = 0    //Բ�뾶��0��ʱ����Բ��
)
{
	setlinecolor(color_line);  // ���õ�ǰ������ɫ 
	setfillcolor(color_full);  // ���õ�ǰ�����ɫ 
	if (!r) {//���û�а뾶�����������ͨ������
		if (line)//����б߿�
			fillrectangle(left, top, right, bottom);
		else
			solidrectangle(left, top, right, bottom);
	}
	else {//�����Բ�ǳ�����
		if (line) {//����б߿�
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
	cleardevice();//������
	out_long(10, 10, 50, 50);//Ĭ�����
	out_long(10, 60, 50, 100, true);//���߿�
	out_long(10, 110, 50, 150, true, 0xAAAAAA);//���߿�,������ڲ���ɫ
	out_long(10, 160, 50, 200, true, 0x00Bfff, 0xFF3030);//���߿�,������ڲ���ɫ�������˱߿�ɫ
	out_long(10, 210, 50, 250, true, 0xffffff, 0xFF3030, 20);//���߿�,������ڲ���ɫ�������˱߿�ɫ,�����˱߽ǵİ뾶
	//�²ۣ�һ����Բ��Բ�ǳ�����
	out_long(10, 260, 200, 400, true, 0xAAAAAA, 0xADFF2F, 20);//���߿�,������ڲ���ɫ�������˱߿�ɫ,�����˱߽ǵİ뾶
	//������
	out_long(10, 410, 400, 490, true, 0xf0f0f0, 0x87CEFA, 20);//���߿�,������ڲ���ɫ�������˱߿�ɫ,�����˱߽ǵİ뾶
	_getch();//�������оͻ���getch();
	closegraph();
	return 0;
}
